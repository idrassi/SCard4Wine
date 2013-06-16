#! /bin/sh
WINE_LIB32_PREFIX=/usr/lib/i386-linux-gnu/wine
WINE_LIB64_PREFIX=/usr/lib/x86_64-linux-gnu/wine
INSTALLATION_OK=0

if [ ! -d "$WINE_LIB64_PREFIX" ]; then
	if [ -n "`file /usr/lib/wine/winscard.dll.so | grep '64-bit'`" ]; then
		WINE_LIB64_PREFIX=/usr/lib/wine
	else
		WINE_LIB64_PREFIX=/usr/lib64/wine
	fi
fi


if [ ! -d "$WINE_LIB32_PREFIX" ]; then	
	if [ -n "`file /usr/lib/wine/winscard.dll.so | grep '32-bit'`" ]; then
		WINE_LIB32_PREFIX=/usr/lib/wine
	else
		WINE_LIB32_PREFIX=/usr/lib32/wine
	fi
fi

if [ -d "$WINE_LIB32_PREFIX" ]; then
	/usr/bin/install -c   32-bit/winscard.dll.so $WINE_LIB32_PREFIX/winscard.dll.so
	/usr/bin/install -c  -m 644  libwinscard.def $WINE_LIB32_PREFIX/libwinscard.def
	echo "New 32-Bit Winscard dll installed successfully."
	INSTALLATION_OK=1
fi

if [ -d "$WINE_LIB64_PREFIX" ]; then
	/usr/bin/install -c   64-bit/winscard.dll.so $WINE_LIB64_PREFIX/winscard.dll.so
	/usr/bin/install -c  -m 644  libwinscard.def $WINE_LIB64_PREFIX/libwinscard.def
	echo "New 64-Bit Winscard dll installed successfully."
	INSTALLATION_OK=1
fi

if [ INSTALLATION_OK = 0 ]; then
	echo "Failed to detect WINE. Installation aborted!"
fi


