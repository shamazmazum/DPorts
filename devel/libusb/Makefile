# Created by: John Reynolds <johnjen@reynoldsnet.org>
# $FreeBSD: devel/libusb/Makefile 315508 2013-03-28 23:47:21Z eadler $

PORTNAME=	libusb
PORTVERSION=	0.1.12
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-0.1%20%28LEGACY%29/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library giving userland programs access to USB devices

OPTIONS_DEFINE=	SGML
SGML_DESC=	Install developer guide from SGML

NO_STAGE=	yes
.include <bsd.port.pre.mk>

DEPRECATED=	has been already included into base system
EXPIRATION_DATE=	2012-04-30

.if ${OPSYS} == "FreeBSD"
.if ${OSVERSION} >= 800069
IGNORE=		has been already included into base system
.endif
.endif

.if ${OPSYS} == DragonFly
.if ${DFLYVERSION} >= 300703
IGNORE=		has been already included into base system
.endif
.endif

.if ${PORT_OPTIONS:MSGML}
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/jade/catalog:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/sgml/docbook/dsssl/modular/catalog:${PORTSDIR}/textproc/dsssl-docbook-modular \
		${LOCALBASE}/share/sgml/docbook/4.2/catalog:${PORTSDIR}/textproc/docbook-420
MAKE_ENV+=	SGML_CATALOG_FILES=${LOCALBASE}/share/sgml/iso8879/catalog:${LOCALBASE}/share/sgml/docbook/4.2/catalog:${LOCALBASE}/share/sgml/docbook/dsssl/modular/catalog:${LOCALBASE}/share/sgml/jade/catalog
PLIST_SUB=	SGML=""
.else
CONFIGURE_ARGS=	--disable-build-docs
PLIST_SUB=	SGML="@comment "
.endif

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|{libdir}/pkgconfig|{prefix}/libdata/pkgconfig|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' ${WRKSRC}/descriptors.c

post-install:
.if ${PORT_OPTIONS:MSGML}
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
