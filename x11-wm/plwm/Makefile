# Created by: Mike Meyer <mwm@mired.org>
# $FreeBSD$

PORTNAME=	plwm
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	x11-wm python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A window manager construction kit

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib

INFO=		plwm

USES=		makeinfo
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's,whrandom,random,g' ${WRKSRC}/plwm/inspect.py
	${REINPLACE_CMD} -e 's,$$Id,coding: utf-8 ,g' ${WRKSRC}/plwm/mw_apm.py

pre-install:
	makeinfo -o ${PREFIX}/info/plwm.info ${WRKSRC}/doc/plwm.texi

.include <bsd.port.mk>
