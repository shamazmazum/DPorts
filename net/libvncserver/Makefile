# Created by: ijliao
# $FreeBSD$

PORTNAME=	libvncserver
PORTVERSION=	0.9.9
PORTREVISION=	8
CATEGORIES=	net devel
MASTER_SITES=	SF
DISTNAME=	LibVNCServer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Provide an easy API to a custom vnc server

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

USES=		libtool pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-x
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GNUTLS OPENSSL GCRYPT IPV6
OPTIONS_DEFAULT=OPENSSL
GCRYPT_DESC=	libgcrypt support

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls

OPENSSL_CONFIGURE_WITH=	crypto ssl
OPENSSL_USE=		OPENSSL=yes

GCRYPT_LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
GCRYPT_CONFIGURE_WITH=	gcrypt

IPV6_CONFIGURE_WITH=	ipv6

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|x11vnc||g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/rfb/default8x16.h ${STAGEDIR}${PREFIX}/include/rfb

.include <bsd.port.mk>
