# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	p11-kit
PORTVERSION=	0.20.3
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://p11-glue.freedesktop.org/releases/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for loading and enumerating of PKCS\#11 modules

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
BUILD_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
LIB_DEPENDS=	libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libffi.so:${PORTSDIR}/devel/libffi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --enable-debug=no \
		--with-trust-paths=${LOCALBASE}/share/certs/ca-root-nss.crt \
		ac_cv_func_pthread_mutexattr_init=no
MAKE_ENV=	exampledir=${STAGEDIR}${EXAMPLESDIR}

USES=		gmake libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} -e \
	's|exampledir = $$(p11_system_config)|exampledir = ${EXAMPLESDIR}|' \
	${WRKSRC}/${PORTNAME}/Makefile.in

.include <bsd.port.mk>
