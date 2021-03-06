# $FreeBSD$

PORTNAME=		ntdb
PORTVERSION=		1.0
PORTREVISION=		0
PORTEPOCH=		0
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SAMBA}
MASTER_SITE_SUBDIR=	tdb

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Not so Trivial DataBase

LICENSE=		GPLv3

CONFLICTS=

USES=			compiler pkgconfig
USE_PYTHON_BUILD=	2
USE_LDCONFIG=		yes
WAF_TOOL=		buildtools/bin/waf
CONFIGURE_LOG=		bin/config.log

PKGCONFIGDIR?=		${PREFIX}/libdata/pkgconfig
PLIST_SUB+=		PKGCONFIGDIR=${PKGCONFIGDIR:S;${PREFIX}/;;}

CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--mandir=${MANPREFIX}/man \
			--infodir=${PREFIX}/${INFO_PATH}/${INFO_SUBDIR} \
			--without-gettext
# Support staging
DESTDIRNAME=		--destdir

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MMANPAGES}
CONFIGURE_ENV+=		XSLTPROC="true"
.else
BUILD_DEPENDS+=		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl \
			xsltproc:${PORTSDIR}/textproc/libxslt
.endif

PLIST_FILES=		bin/ntdbbackup \
			bin/ntdbdump \
			bin/ntdbrestore \
			bin/ntdbtool \
			include/ntdb.h \
			lib/libntdb.so \
			lib/libntdb.so.1 \
			%%PKGCONFIGDIR%%/ntdb.pc

# No fancy color error messages
.if ${COMPILER_TYPE} == "clang"
CFLAGS+=		-fno-color-diagnostics
.endif
CONFIGURE_ENV+=		NOCOLOR=yes
MAKE_ENV+=		NOCOLOR=yes

.if !defined(DISABLE_MAKE_JOBS) && !defined(MAKE_JOBS_UNSAFE)
CONFIGURE_ARGS+=	--jobs=${MAKE_JOBS_NUMBER}
_MAKE_JOBS+=		--jobs=${MAKE_JOBS_NUMBER}
.endif

.if defined(NO_PYTHON)
CONFIGURE_ARGS+=	--disable-python
.else
USE_PYTHON_RUN=		yes
PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/ntdb.so
PLIST_DIRSTRY+=		%%PYTHON_SITELIBDIR%% \
			%%PYTHON_LIBDIR%%
.endif

TDB_MAN3=		man/man3/ntdb.3.gz

TDB_MAN8=		man/man8/ntdbbackup.8.gz \
			man/man8/ntdbdump.8.gz \
			man/man8/ntdbrestore.8.gz \
			man/man8/ntdbtool.8.gz

PLIST_FILES+=		${TDB_MAN3} ${TDB_MAN8}

CONFIGURE_TARGET=	configure
ALL_TARGET=		build
INSTALL_TARGET=		install

IGNORE_NONTHREAD_PYTHON=needs port lang/python${PYTHON_SUFFIX} to be build with THREADS support

post-patch:
			@${REINPLACE_CMD} -e 's|%%PKGCONFIGDIR%%|${PKGCONFIGDIR}|g' \
				${BUILD_WRKSRC}/wscript

# Use threading (or multiprocessing) but not thread (renamed in python 3+).
pre-configure:
			@if ! ${PYTHON_CMD} -c "import multiprocessing;" 2>/dev/null; then \
				${ECHO_CMD}; \
				${ECHO_MSG} "===>  ${PKGNAME} "${IGNORE_NONTHREAD_PYTHON:Q}.; \
				${ECHO_CMD}; \
				${FALSE}; \
			fi

do-configure:
			@(cd ${CONFIGURE_WRKSRC} && \
			    ${SET_LATE_CONFIGURE_ARGS} \
				if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
					CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
					LDFLAGS="${LDFLAGS}" \
					INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
					INSTALL_DATA="${INSTALL_DATA}" \
					INSTALL_LIB="${INSTALL_LIB}" \
					INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
					INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
					${CONFIGURE_ENV} ${PYTHON_CMD} ${CONFIGURE_WRKSRC}/${WAF_TOOL} ${CONFIGURE_ARGS} ${CONFIGURE_TARGET}; then \
						${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
						(${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
						${FALSE}; \
				fi)

pre-build:
.if ! ${PORT_OPTIONS:MMANPAGES}
			-${MKDIR} ${BUILD_WRKSRC}/bin/default/man
.	for man in ${TDB_MAN3} ${TDB_MAN8}
			${INSTALL_MAN} ${FILESDIR}/`basename ${man} .gz` ${BUILD_WRKSRC}/bin/default/man
.	endfor
.endif

do-build:
			@(cd ${BUILD_WRKSRC}; \
			if ! ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${BUILD_WRKSRC}/${WAF_TOOL} ${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}; then \
				if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
					${ECHO_MSG} "===> Compilation failed unexpectedly."; \
					(${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
				fi; \
			${FALSE}; \
			fi)

do-install:
			@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${INSTALL_WRKSRC}/${WAF_TOOL} ${MAKE_ARGS} ${INSTALL_TARGET})

.include <bsd.port.post.mk>
