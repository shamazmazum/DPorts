# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	tetgen
PORTVERSION=	1.4.3.20110119
CATEGORIES=	math
MASTER_SITES=	http://wias-berlin.de/software/tetgen/files/
DISTNAME=	${PORTNAME}${PORTVERSION:R}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quality Tetrahedral Mesh Generator and Delaunay Triangulator

LICENSE_FILE=	${WRKDIR}/LICENSE

NO_CDROM=	Tetgen is for academic or personal use only

OPTIONS_DEFINE=	EXAMPLES

MAKEFILE=	makefile
ALL_TARGET=	tetgen tetlib

PORTEXAMPLES=	example.poly
PLIST_FILES=	bin/tetgen include/tetgen.h lib/libtet.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tetgen ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tetgen.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libtet.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.poly ${STAGEDIR}${EXAMPLESDIR}

regression-test:
	(cd ${INSTALL_WRKSRC} && ./tetgen -p example.poly )

.include <bsd.port.mk>
