#! /bin/sh
WINE_LIB_PREFIX=/usr/lib/wine

if [ ! -d "$WINE_LIB_PREFIX" ]; then
	# this the new multi-arch lib directory under Debian/Ubuntu
	WINE_LIB_PREFIX=/usr/lib/i386-linux-gnu/wine
fi

if [ -d "$WINE_LIB_PREFIX" ]; then
	/usr/bin/install -c   winscard.dll.so $WINE_LIB_PREFIX/winscard.dll.so
	/usr/bin/install -c  -m 644  libwinscard.def $WINE_LIB_PREFIX/libwinscard.def
	echo "New Winscard dll installed successfully."
else
	echo "Failed to find WINE installation."
fi



