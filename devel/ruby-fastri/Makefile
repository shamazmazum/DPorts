# Created by: stas
# $FreeBSD$

PORTNAME=	fastri
PORTVERSION=	0.3.1
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast RDoc documentation browser for ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}"

DOCS=		CHANGES README.en

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
