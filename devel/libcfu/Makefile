# $FreeBSD$

PORTNAME=	libcfu
DISTVERSION=	0.04a
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Simple library of tools for developing multithreaded software

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	crees
GH_COMMIT=	947dba4
GH_TAGNAME=	947dba4

USES=		makeinfo pkgconfig pathfix libtool
PATHFIX_MAKEFILEIN=	Makefile.am

USE_AUTOTOOLS=	autoconf autoheader automake aclocal libtoolize
AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	-I ${LIBTOOL_M4:C,[^/]*$,,}
INFO=		${PORTNAME}

# XXX: work around an issue with automake-1.13 erroring out on a
#      non-existent m4 directory before libtoolize creates it
pre-configure::
	@${MKDIR} ${WRKSRC}/m4

.include <bsd.port.mk>
