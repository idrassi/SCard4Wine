/*
 * Copyright 2007 Mounir IDRASSI  (mounir.idrassi@idrix.fr, for IDRIX)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */


#ifndef _WINE_WINSCMCRD_H
#define _WINE_WINSCMCRD_H


#define MAX_ATR_SIZE			36	/* Maximum ATR size */

#ifndef SCARD_ATR_LENGTH
#define SCARD_ATR_LENGTH		MAX_ATR_SIZE
#endif

/*
 * These values define the protocol used to
 * communicate with the card
 */
#define SCARD_PROTOCOL_UNDEFINED    0x00000000  /* No protocol defined */
#define SCARD_PROTOCOL_T0           	0x00000001  /* T=0 protocol. */
#define SCARD_PROTOCOL_T1           	0x00000002  /* T=1 protocol */
#define SCARD_PROTOCOL_RAW          	0x00010000  /* Raw protocol, for memory card for example */
#define SCARD_PROTOCOL_Tx          	 (SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1) /* Can be used in SCardConnect */

/*
 * The following value is used as a length value
 * in functions where we want the winscard dll
 * to allocate memory for us
 */
#define SCARD_AUTOALLOCATE (DWORD)(-1)

/*
 * Values used by SCardEstablishContext
 */
#define SCARD_SCOPE_USER			0x0000	/* context in user scope */
#define SCARD_SCOPE_TERMINAL		0x0001	/* context in terminal scope */
#define SCARD_SCOPE_SYSTEM		0x0002	/* context in system scope */

/*
 * Flags used by SCardGetStatusChange to indicate
 * the reader status.
 */
#define SCARD_STATE_UNAWARE		0x0000	/* called want to know the current state */
#define SCARD_STATE_IGNORE		0x0001	/* don't update the state for the given reader */
#define SCARD_STATE_CHANGED		0x0002	/* reader state has not changed */
#define SCARD_STATE_UNKNOWN		0x0004	/* reader state unknown */
#define SCARD_STATE_UNAVAILABLE	0x0008	/* reader state unavailable */
#define SCARD_STATE_EMPTY			0x0010	/* no card on the reader*/
#define SCARD_STATE_PRESENT		0x0020	/* card present on the reader */
#define SCARD_STATE_ATRMATCH		0x0040	/* card's ATR matches the given ATR */
#define SCARD_STATE_EXCLUSIVE		0x0080	/* an exclusive connection on the card exists*/
#define SCARD_STATE_INUSE			0x0100	/* card in use but the connection can be shared */
#define SCARD_STATE_MUTE			0x0200	/* card is mute, doesn't answer to reset */
#define SCARD_STATE_UNPOWERED	0x0400	/* card present but not powered */


/*
 * These values define how SCardConnect should
 * connect to the card
 */
#define SCARD_SHARE_EXCLUSIVE		0x0001	/* connect to the card in exclusive mode (no other connection allowed) */
#define SCARD_SHARE_SHARED		0x0002	/* connection can be shared with others */
#define SCARD_SHARE_DIRECT		0x0003	/* access directly the reader, no other connection allowed */

/*
 * Values used by SCardDisconnect to specify
 * how the card should be treated on closing
 * the connection
 */
#define SCARD_LEAVE_CARD			0x0000	/* do nothing */
#define SCARD_RESET_CARD			0x0001	/* reset the card */
#define SCARD_UNPOWER_CARD		0x0002	/* unpower the card */
#define SCARD_EJECT_CARD			0x0003	/* eject the card from the reader if supported */

/*
 * Values returned by SCardStatus indicating
 * the reader's state
 */
#define SCARD_UNKNOWN			0x0001	/* state unknown */
#define SCARD_ABSENT				0x0002	/* no card on the reader */
#define SCARD_PRESENT				0x0004	/* card is present on the reader */
#define SCARD_SWALLOWED			0x0008	/* card inside the reader but not powered */
#define SCARD_POWERED			0x0010	/* card present and powered */
#define SCARD_NEGOTIABLE			0x0020	/* card present and ready to negotiate protocol */
#define SCARD_SPECIFIC				0x0040	/* card has ended protocol negotiation */

/*
 * definitions used by SCardGetAttrib and SCardSetAttrib for
 * requesting and setting readers attributes
 * Other values maybe supported
 */
#define SCARD_ATTR_ICC_PRESENCE 			0x00090300
#define SCARD_ATTR_CURRENT_PROTOCOL_TYPE 	0x00080201
#define SCARD_ATTR_ATR_STRING 				0x00090303
#define SCARD_ATTR_DEVICE_FRIENDLY_NAME_A 	0x7FFF0003
#define SCARD_ATTR_DEVICE_FRIENDLY_NAME_W 	0x7FFF0005
#define SCARD_ATTR_DEVICE_SYSTEM_NAME_A 	0x7FFF0004
#define SCARD_ATTR_DEVICE_SYSTEM_NAME_W 	0x7FFF0006

#define SCARD_ATTR_DEVICE_FRIENDLY_NAME 	WINELIB_NAME_AW(SCARD_ATTR_DEVICE_FRIENDLY_NAME_)
#define SCARD_ATTR_DEVICE_SYSTEM_NAME 		WINELIB_NAME_AW(SCARD_ATTR_DEVICE_SYSTEM_NAME_)

	
/*
 * This structure is used by SCardTransmit to communicate
 * with the card
 */
typedef struct _SCARD_IO_REQUEST
{
	unsigned long dwProtocol;	/* protocol used for this request */
	unsigned long cbPciLength;	/* total length of the request data, usually sizeof(SCARD_IO_REQUEST) */
}
SCARD_IO_REQUEST, *PSCARD_IO_REQUEST, *LPSCARD_IO_REQUEST;

typedef const SCARD_IO_REQUEST *LPCSCARD_IO_REQUEST;

#endif
