# $FreeBSD$

PORTNAME=	skanlite
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple image scanning application for KDE

LIB_DEPENDS=	libksane.so:${PORTSDIR}/graphics/libksane

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
USES=		cmake:outsource tar:xz

.include <bsd.port.mk>
