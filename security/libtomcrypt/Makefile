# Created by: Yonatan <Yonatan@Xpert.com>
# $FreeBSD$

PORTNAME=	libtomcrypt
PORTVERSION=	1.17
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://libtom.org/files/
DISTNAME=	crypt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive, modular, and portable cryptographic toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKEFILE=	makefile
MAKE_ARGS=	DESTDIR="${STAGEDIR}" LIBPATH="${PREFIX}/lib" \
		INCPATH="${PREFIX}/include" DATAPATH="${DOCSDIR}/pdf"

USES=		gmake tar:bzip2
ALL_TARGET=	library

CFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	LIBTOMMATH
OPTIONS_MULTI=	MATH
OPTIONS_MULTI_MATH=	LIBTOMMATH TOMSFASTMATH GMP
LIBTOMMATH_DESC=	Use LibTomMath
TOMSFASTMATH_DESC=	Use TomsFastMath

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBTOMMATH}
BUILD_DEPENDS+=	${LOCALBASE}/include/tommath.h:${PORTSDIR}/math/libtommath
CFLAGS+=	-DLTM_DESC
.endif

.if ${PORT_OPTIONS:MTOMSFASTMATH}
BUILD_DEPENDS+=	${LOCALBASE}/include/tfm.h:${PORTSDIR}/math/tomsfastmath
CFLAGS+=	-DTFM_DESC
.endif

.if ${PORT_OPTIONS:MGMP}
BUILD_DEPENDS+=	${LOCALBASE}/include/gmp.h:${PORTSDIR}/math/gmp
CFLAGS+=	-DGMP_DESC
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build dvipdfmx:build
PORTDOCS=	*
.else
MAKE_ARGS+=	NODOCS=yes
.endif

.if defined(MAINTAINER_MODE)
test:	build
	@${ECHO_MSG} "Testing with -DUSE_TFM..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_TFM" EXTRALIBS="-L${PREFIX}/lib -ltfm" ${MAKE_CMD} test && ${WRKSRC}/test)

	@${ECHO_MSG} "Cleaning up test binary..."
	@${RM} ${WRKSRC}/test
	@${RM} ${WRKSRC}/demos/test.o

	@${ECHO_MSG} "Testing with -DUSE_LTM..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_LTM" EXTRALIBS="-L${PREFIX}/lib -ltommath" ${MAKE_CMD} test && ${WRKSRC}/test)

	@${ECHO_MSG} "Cleaning up test binary..."
	@${RM} ${WRKSRC}/test
	@${RM} ${WRKSRC}/demos/test.o

	@${ECHO_MSG} "Testing with -DUSE_GMP..."
	(cd ${WRKSRC} && CFLAGS="${CFLAGS} -DUSE_GMP" EXTRALIBS="-L${PREFIX}/lib -lgmp" ${MAKE_CMD} test && ${WRKSRC}/test)
.endif

.include <bsd.port.mk>
