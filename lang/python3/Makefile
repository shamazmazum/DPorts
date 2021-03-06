# $FreeBSD$

PORTNAME=	python3
PORTVERSION=	${PYTHON_MAJOR_VER}
PORTREVISION=	1
CATEGORIES=	lang python ipv6
MASTER_SITES=
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	python@FreeBSD.org
COMMENT=	The "meta-port" for version 3 of the Python interpreter

USE_PYTHON_RUN=	yes
PYTHON_VERSION=	${PYTHON3_DEFAULT_VERSION}
NO_BUILD=	yes
PYTHON_NO_DEPENDS=	yes

PLIST_FILES=	bin/2to3-${PYTHON_MAJOR_VER} \
		bin/idle${PYTHON_MAJOR_VER} \
		bin/pydoc${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER} \
		bin/python${PYTHON_MAJOR_VER}-config \
		bin/python-shared${PYTHON_MAJOR_VER} \
		bin/python-shared${PYTHON_MAJOR_VER}-config \
		libdata/pkgconfig/python${PYTHON_MAJOR_VER}.pc

.include <bsd.port.pre.mk>

RUN_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}

do-install:
.for file in python python-shared
	${LN} -sf ${file}${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/${file}${PYTHON_MAJOR_VER}
.endfor
	${LN} -sf 2to3-${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/2to3-${PYTHON_MAJOR_VER}
.for file in idle pydoc
	${LN} -sf ${file}${PYTHON_MAJOR_VER}-${PYTHON_VER} \
		${STAGEDIR}${PREFIX}/bin/${file}${PYTHON_MAJOR_VER}
.endfor
	${LN} -sf python${PYTHON_VER}-config \
		${STAGEDIR}${PREFIX}/bin/python${PYTHON_MAJOR_VER}-config
	${LN} -sf python-shared${PYTHON_VER}-config \
		${STAGEDIR}${PREFIX}/bin/python-shared${PYTHON_MAJOR_VER}-config
	${LN} -sf python-${PYTHON_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/python${PYTHON_MAJOR_VER}.pc

# Major upgrade support
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portupgrade

.if defined(USE_PORTMASTER)
PORTUPGRADE_CMD=	${LOCALBASE}/sbin/portmaster
.endif

.if defined(WITH_PKGNG)
PKG_LIST=	${PKG_BIN} query -a '%n-%v'
PKG_LIST_FILES=	${PKG_INFO} -l
.else
PKG_LIST=	${PKG_INFO} -Ea
PKG_LIST_FILES=	${PKG_INFO} -L
.endif

.include <bsd.port.post.mk>
