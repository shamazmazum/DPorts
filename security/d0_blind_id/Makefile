# $FreeBSD$

PORTNAME=	d0_blind_id
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security devel

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Crypto library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	divVerent
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ff1ce7e

USES=		libtool
CONFIGURE_ARGS=	--with-openssl
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	--add-missing

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libd0_rijndael.so.0

.include <bsd.port.mk>
