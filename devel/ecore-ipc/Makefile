# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ipc
PORTVERSION=	1.7.9
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	ecore-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (ipc module)

LICENSE=	BSD

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USE_EFL=	ecore libtool_hack
USE_EFL_ECORE=	con
USES=		gmake pkgconfig tar:bzip2
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_ipc
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ENV=		SSL_CFLAGS="-I${OPENSSLINC} -L${OPENSSLLIB}" SSL_LIBS="-lssl"
CONFIGURE_ARGS+=	--enable-openssl
.else
CONFIGURE_ARGS+=	--disable-openssl
.endif

.include "../ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-con \
			--enable-ecore-ipc

LDFLAGS+=	-L${LOCALBASE}/lib -lecore -lecore_con

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_con/libecore_con\.la,,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-ipc.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
