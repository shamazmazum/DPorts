# $FreeBSD$

PORTNAME=	xf86-input-fpit
PORTVERSION=	1.4.0
PORTREVISION=	3
CATEGORIES=	x11-drivers

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org fpit input driver

XORG_CAT=	driver
USE_XORG=	xrandr

.include <bsd.port.options.mk>

.if !defined(WITH_NEW_XORG)
IGNORE=		does not build with X server 1.7.7
.endif

.include <bsd.port.mk>
