# Created by: Matthew Gibson <mdg583@hotmail.com>
# $FreeBSD$

PORTNAME=	cuyo
PORTVERSION=	2.0.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	games@FreeBSD.org
COMMENT=	Nice, innovative, challenging Tetris-like game

LICENSE=	GPLv2

LIB_DEPENDS=	libaa.so:${PORTSDIR}/graphics/aalib \
		libmikmod.so:${PORTSDIR}/audio/libmikmod

USES=		iconv
GNU_CONFIGURE=	yes
USE_SDL=	mixer image
USE_XORG=	xdmcp xau x11
INSTALLS_ICONS=	yes

PORTDOCS=	AUTHORS NEWS TODO

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext:run

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MNLS}
. for f in de
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES ; \
		${INSTALL_DATA} ${WRKSRC}/po/${f}.gmo \
		${STAGEDIR}${PREFIX}/share/locale/${f}/LC_MESSAGES/${PORTNAME}.mo
. endfor
.endif

	${LN} -sf ${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
