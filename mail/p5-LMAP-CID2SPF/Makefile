# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	LMAP-CID2SPF
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.baschny.de/spf/
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Module to convert between Microsoft's Caller-ID and SPF		#'

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	cid2spf

do-install:
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/LMAP
	cd ${WRKSRC} && ${INSTALL_SCRIPT} cid2spf ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} CID2SPF.pm ${STAGEDIR}${SITE_PERL}/LMAP

.include <bsd.port.mk>
