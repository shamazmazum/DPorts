# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	mydumper
PORTVERSION=	0.6.1
CATEGORIES=	databases
MASTER_SITES=	http://code.launchpad.net/mydumper/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	MySQL Data Dumper

LICENSE=	GPLv3

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

USE_GNOME=	glib20
USE_MYSQL=	yes
USES=		cmake pkgconfig

PLIST_FILES=	sbin/mydumper sbin/myloader

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' ${WRKSRC}/CMakeLists.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mydumper ${WRKSRC}/myloader ${STAGEDIR}${PREFIX}/sbin/

.include <bsd.port.mk>
