# Created by: ijliao
# $FreeBSD$

PORTNAME=	latex-mk
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	misc print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of makefile and scripts for LaTeX documents

BUILD_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo
RUN_DEPENDS=	texi2dvi:${PORTSDIR}/print/texinfo

USE_TEX=	latex
USES=		gmake
GNU_CONFIGURE=	yes

LICENSE=	BSD

INFO=		latex-mk

NO_STAGE=	yes
.include <bsd.port.mk>
