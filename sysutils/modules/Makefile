# Created by: Hokan
# $FreeBSD$

PORTNAME=	modules
PORTVERSION=	3.1.6
CATEGORIES=	sysutils tcl
MASTER_SITES=	SF/${PORTNAME}/Modules/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic modification of a user's environment

LIB_DEPENDS=	libtcl${TCL_VER}.so:${PORTSDIR}/lang/tcl${TCL_VER}

PLIST_SUB=	MODULES_VERSION=${PORTVERSION}

BINDIR=		${PREFIX}/Modules

TCL_DVER?=	8.4
TCL_VER=	${TCL_DVER:S/.//}
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}/Modules/@VERSION@ \
		--without-x \
		--with-version-path=${PREFIX}/Modules/versions \
		--mandir=${MANPREFIX}/man \
		--with-tcl-version=${TCL_VER} \
		--with-tcl-include=${LOCALBASE}/include/tcl${TCL_DVER} \
		--with-tcl-libraries=${LOCALBASE}/lib/

MAN1=		module.1
MAN5=		modulefile.5

NO_STAGE=	yes
post-extract:
		${MV} ${WRKSRC}/doc/modulefile.4.in ${WRKSRC}/doc/modulefile.5.in

pre-install:
		${MKDIR} ${PREFIX}/Modules

.include <bsd.port.mk>
