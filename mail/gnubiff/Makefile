# Created by: Tim Bishop <tim@bishnet.net>
# $FreeBSD$

PORTNAME=	gnubiff
PORTVERSION=	2.2.13
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Mail notification program for Gnome

OPTIONS_DEFINE=	NLS

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt

USE_GNOME=	intlhack libglade2 esound
USES=		fam gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# CXXFLAGS needed to work round issue with gcc and openssl 0.9.8a
# /usr/local/include/openssl/sha.h:173: error: ISO C++ does not support `long long'
CXXFLAGS+=	"-Wno-long-long"

INFO=		gnubiff

.include <bsd.port.options.mk>

.ifdef(WITH_GNUBIFF_PASSWORD)
CONFIGURE_ARGS+=	--with-password
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
USES+=		gettext
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

CONFIGURE_ARGS+=	--disable-gnome
PLIST_SUB+=		BONOBODIR="libdata/bonobo"

.include <bsd.port.mk>
