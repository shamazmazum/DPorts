# Created by: glewis
# $FreeBSD$

PORTNAME=	szip
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	science archivers
MASTER_SITES=	http://www.hdfgroup.org/ftp/lib-external/${PORTNAME}/${PORTVERSION}/src/:src \
		http://www.hdfgroup.org/doc_resource/SZIP/:doc \
		LOCAL/sunpoet:src,doc
PKGNAMEPREFIX=	hdf-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${PORTDOCS}:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lossless compression library for scientific data

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
LDFLAGS+=	-lm
USE_LDCONFIG=	yes
USES=		libtool

PLIST_FILES=	include/ricehdf.h \
		include/szip_adpt.h \
		include/szlib.h \
		lib/libsz.a \
		lib/libsz.so \
		lib/libsz.so.2 \
		lib/libsz.so.2.0.0
PORTDOCS=	Release_notes_2_0.pdf

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsz.so.2.0.0

regression-test test: build
	cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
