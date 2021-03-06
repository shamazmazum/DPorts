# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	pgbouncer
PORTVERSION=	1.5.4
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3393/

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Lightweight connection pooler for PostgreSQL

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto
.endif

PORTSCOUT=	site:http://pgfoundry.org/frs/?group_id=1000258

USERS=		pgbouncer
GROUPS=		pgbouncer

USE_RC_SUBR=	pgbouncer

GNU_CONFIGURE=	yes
USES=		gmake

CONFIGURE_ARGS=	--with-libevent=${LOCALBASE} --enable-evdns
CONFIGURE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} \
		PTHREAD_LIBS=${PTHREAD_LIBS}

PGBOUNCER_USER?=	pgbouncer
PGBOUNCER_GROUP?=	pgbouncer

PGBOUNCER_RUNDIR?=	/var/run/pgbouncer
PGBOUNCER_LOGDIR?=	/var/log/pgbouncer

BUILD_DEPENDS+=		${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

.include <bsd.port.pre.mk>

PLIST_SUB+=	PGBOUNCER_USER="${USERS}" \
		PGBOUNCER_GROUP="${GROUPS}" \
		PGBOUNCER_LOGDIR="${PGBOUNCER_LOGDIR}" \
		PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}"

SUB_LIST+=	PGBOUNCER_RUNDIR="${PGBOUNCER_RUNDIR}"

post-patch:
	@${REINPLACE_CMD} -e "s|= pgbouncer.log|= ${PGBOUNCER_LOGDIR}/pgbouncer.log|g" \
		-e "s|= pgbouncer.pid|= ${PGBOUNCER_RUNDIR}/pgbouncer.pid|g" \
		${WRKSRC}/etc/pgbouncer.ini
	@${REINPLACE_CMD} -e "s|sed -n|${LOCALBASE}/bin/gsed -n|g" \
		${WRKSRC}/lib/find_modules.sh

.if empty(PORT_OPTIONS:MDOCS)
	${REINPLACE_CMD} -e "s| = doc| = |g" ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgbouncer ${STAGEDIR}${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.5 ${STAGEDIR}${PREFIX}/man/man5/
.endif
	${INSTALL_DATA} ${WRKSRC}/etc/pgbouncer.ini ${STAGEDIR}${PREFIX}/etc/pgbouncer.ini.sample
	${INSTALL_DATA} ${WRKSRC}/etc/userlist.txt ${STAGEDIR}${PREFIX}/etc/pgbouncer.users.sample

.include <bsd.port.post.mk>
