# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	55-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mariadb55-server

FILESDIR=	${.CURDIR}/files
PATCHDIR=	${.CURDIR}/files
DFLY_PATCHDIR=	${.CURDIR}/dragonfly
PLIST=		${.CURDIR}/pkg-plist

CONFLICTS_INSTALL=	mysql[0-9][0-9]-client-* mariadb[0-46-9][0-9]-client-* mariadb5.[0-46-9]-client-* percona[0-9][0-9]-client-*

CMAKE_ARGS+=	-DWITHOUT_SERVER=1

USE_LDCONFIG=	${PREFIX}/lib/mysql

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
