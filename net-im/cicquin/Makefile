# Created by: Peter Pentchev
# $FreeBSD$

PORTNAME=	cicquin
PORTVERSION=	0.1
CATEGORIES=	net-im
#MASTER_SITES=	${MASTER_SITE_LOCAL} \ 
MASTER_SITES=	\
		http://devel.ringlet.net/misc/cicquin/ \
		http://people.FreeBSD.org/~roam/misc/cicquin/
MASTER_SITE_SUBDIR=	roam/misc/cicquin

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Look up users in the CenterICQ user database

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
