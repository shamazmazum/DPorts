# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-time-out-plugin
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	x11-clocks xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Timer out plugin for Xfce

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake libtool pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	configenv libmenu libutil panel

.include <bsd.port.mk>
