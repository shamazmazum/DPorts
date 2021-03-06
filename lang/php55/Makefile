# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	php55
PORTVERSION=	5.5.14
PORTREVISION?=	0
CATEGORIES?=	lang devel www
MASTER_SITES=	${MASTER_SITE_PHP}
MASTER_SITE_SUBDIR=	distributions
DISTNAME=	php-${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	PHP Scripting Language

LICENSE=	PHP301

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

USES=		tar:bzip2 cpe
NO_OPTIONS_SORT=yes
.if !defined(PKGNAMESUFFIX)
USE_AUTOTOOLS=	autoconf

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

CPE_PRODUCT=	php

CONFIGURE_ARGS+=--with-layout=GNU \
		--localstatedir=/var \
		--with-config-file-scan-dir=${PREFIX}/etc/php \
		--disable-all \
		--enable-libxml \
		--enable-mysqlnd \
		--with-libxml-dir=${LOCALBASE} \
		--with-pcre-regex=${LOCALBASE} \
		--with-zlib-dir=/usr \
		--program-prefix=""

USE_GNOME=	libxml2

OPTIONS_DEFINE+=CLI CGI FPM FPM_IPV6 EMBED DEBUG DTRACE IPV6 MAILHEAD LINKTHR ZTS
OPTIONS_DEFAULT=CLI CGI FPM IPV6 LINKTHR
OPTIONS_SUB=	yes

CLI_DESC=	Build CLI version
CGI_DESC=	Build CGI version
FPM_DESC=	Build FPM version
FPM_IPV6_DESC=	Enable ipv6 patch for FPM
EMBED_DESC=	Build embedded library
DEBUG_DESC=	Enable debug
DTRACE_DESC=	Enable DTrace support
IPV6_DESC=	Enable ipv6 support
MAILHEAD_DESC=	Enable mail header patch
LINKTHR_DESC=	Link thread lib (for threaded extensions)
ZTS_DESC=	Force Zend Thread Safety (ZTS) build

CONFLICTS=	php53-5* php54-5* php5-5*

DESTDIRNAME=	INSTALL_ROOT

.include <bsd.port.pre.mk>

PATCH_DIST_STRIP=	-p1

PATCH_SITES+=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	ale

.if ${PORT_OPTIONS:MMAILHEAD}
PATCHFILES+=	php-5.5.x-mail-header.patch:mail
PATCH_SITES+=	http://choon.net/opensource/php/:mail
.endif

.if ${PORT_OPTIONS:MCLI}
PHP_SAPI+=	cli
.else
CONFIGURE_ARGS+=--disable-cli
.endif

.if ${PORT_OPTIONS:MCGI}
PHP_SAPI+=	cgi
.else
CONFIGURE_ARGS+=--disable-cgi
.endif

.if ${PORT_OPTIONS:MFPM}
PHP_SAPI+=	fpm
USE_RC_SUBR+=	php-fpm
CONFIGURE_ARGS+=--enable-fpm \
		--with-fpm-user=${WWWOWN} \
		--with-fpm-group=${WWWGRP}
.if ${PORT_OPTIONS:MIPV6} && ${PORT_OPTIONS:MFPM_IPV6}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-php-fpm-ipv6:-p1
.endif
.endif

.if defined(OPTIONS_FILE_SET) && ${OPTIONS_FILE_SET:MAPACHE}
IGNORE=		doesn't install the Apache module anymore:\
		update your OPTIONS and build www/mod_php55 port instead 
.endif

.if defined(PKGNAMEPREFIX)
USE_PHP=	yes
PHP_DEFAULT=	5.5
IGNORE_WITH_PHP=53 54 5
USE_APACHE=	22+
.include "${PORTSDIR}/Mk/bsd.apache.mk"
.if ${PORT_OPTIONS:MAP2FILTER}
CONFIGURE_ARGS+=--with-apxs2filter=${APXS}
.else
CONFIGURE_ARGS+=--with-apxs2=${APXS}
.endif
PLIST=		${PKGDIR}/pkg-plist.mod
PKGMESSAGE=	${PKGDIR}/pkg-message.mod
MODULENAME=	libphp5
SHORTMODNAME=	php5
WARNING=	"!!! If you have a threaded Apache, you must build ${PHP_PORT} with ZTS support to enable thread-safety in extensions !!!"
.endif

.if ${PORT_OPTIONS:MEMBED}
PHP_SAPI+=	embed
CONFIGURE_ARGS+=--enable-embed
.endif

.if ${PORT_OPTIONS:MCLI} || ${PORT_OPTIONS:MEMBED}
PLIST_SUB+=	SAPI_INC=""
.else
PLIST_SUB+=	SAPI_INC="@comment "
.endif

.if !defined(WITH_REGEX_TYPE) || ${WITH_REGEX_TYPE} == "php"
CONFIGURE_ARGS+=--with-regex=php
.elif defined(WITH_REGEX_TYPE) && ${WITH_REGEX_TYPE} == "system"
CONFIGURE_ARGS+=--with-regex=system
.endif

.if !defined(WITH_ZEND_VM) || ${WITH_ZEND_VM} == "CALL"
CONFIGURE_ARGS+=--with-zend-vm=CALL
.elif defined(WITH_ZEND_VM) && ${WITH_ZEND_VM} == "SWITCH"
CONFIGURE_ARGS+=--with-zend-vm=SWITCH
.elif defined(WITH_ZEND_VM) && ${WITH_ZEND_VM} == "GOTO"
CONFIGURE_ARGS+=--with-zend-vm=GOTO
.endif

CONFIGURE_ENV+=	ac_cv_pthreads_lib="" \
		ac_cv_pthreads_cflags="" \
		pthreads_working="yes" \
		lt_cv_path_SED="sed"

.if ${PORT_OPTIONS:MLINKTHR}
LIBS+=		${PTHREAD_LIBS}
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MZTS}
CONFIGURE_ARGS+=--enable-maintainer-zts
.endif

.if ${PORT_OPTIONS:MDTRACE}
.if ${OSVERSION} < 900000
IGNORE=		cannot be built with DTrace support on FreeBSD < 9.x
.endif
CONFIGURE_ARGS+=--enable-dtrace
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/ext/php_config.h
	@${REINPLACE_CMD} "s|^\(extension_dir\)|; \1|" ${WRKSRC}/php.ini-*
.if ${PORT_OPTIONS:MFPM}
	@${REINPLACE_CMD} -e "s|^;\(pid\)|\1|;s|^;\(pm\.[a-z_]*_servers\)|\1|" \
		${WRKSRC}/sapi/fpm/php-fpm.conf.in
.endif

# Work around issues with newer (>=2.64) autoconf
pre-configure:
	@${REINPLACE_CMD} -E 's:^((m4_)?divert)[(]([0-9]*)[)]:\1(600\3):' \
		${WRKSRC}/configure.in `${FIND} ${WRKSRC} -name '*.m4'`
	@${RM} ${WRKSRC}/configure
	@${CAT} ${WRKSRC}/acinclude.m4 ${WRKSRC}/build/libtool.m4 > ${WRKSRC}/aclocal.m4

.if !defined(PKGNAMEPREFIX)
post-build:
	@${ECHO_CMD} "PHP_VER=55" > ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_VERSION=${PORTVERSION}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_SAPI=${PHP_SAPI}" >> ${WRKDIR}/php.conf
	@${ECHO_CMD} "PHP_EXT_INC=pcre spl" >> ${WRKDIR}/php.conf

test: build
	@(cd ${WRKSRC} && ${MAKE} test)

post-install:
	@${INSTALL_DATA} ${WRKSRC}/php.ini-development ${WRKSRC}/php.ini-production \
		${WRKDIR}/php.conf ${STAGEDIR}/${PREFIX}/etc
.else
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}
	${INSTALL_LIB} ${WRKSRC}/libs/${MODULENAME}.so \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR}
.endif

.else
.include "${MASTERDIR}/Makefile.ext"
.endif
.include <bsd.port.post.mk>
