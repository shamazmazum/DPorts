# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	vnless
PORTVERSION=	1.0
CATEGORIES=	vietnamese
MASTER_SITES=	ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pager utility that speaks Vietnamese

ALL_TARGET=	clobber all
MAN1=		vnless.1 vnlesskey.1

NO_STAGE=	yes
post-install:
	@strip ${PREFIX}/bin/vnless*
	@${CHMOD} a+rx ${PREFIX}/bin/vnless*
	@${CHMOD} a+r ${PREFIX}/share/misc/vnless.help
	@${CHMOD} a+r ${PREFIX}/man/man1/vnless*.1*

.include <bsd.port.mk>
