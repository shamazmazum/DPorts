# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	gtksql
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-testing/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical query tool for PostgreSQL/MySQL/SQLite

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libscintilla.so:${PORTSDIR}/x11-toolkits/scintilla
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=	AVAHI DOCS
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CPPFLAGS+=	-I${LOCALBASE}/include/scintilla -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lscintilla -lscintilla_lexers

PGSQL_USES=	pgsql
PGSQL_CONFIGURE_WITH=	postgresql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	libavahi-common.so:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=	--without-avahi
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CPPFLAGS+=	-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
.else
CONFIGURE_ARGS+=	--without-sqlite
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/-lstdc++/s|^|#| ; \
		 /scintilla.a/s|^|#| ; \
		 /\/scintilla\/include/s|^|#| ; \
		 /ac_header/s|postgres.h|libpq-fe.h| ; \
		 /^packagedatadir/s|=.*|=share/gtksql|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-O1|| ; \
		 s|-g$$|-DGTK|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|<postgres\.h>|<postgresql/internal/c.h>|' \
		${WRKSRC}/src/d_postgres_f.c
	@${REINPLACE_CMD} -e \
		's|mozilla|xdg-open|' \
		${WRKSRC}/src/gtkui-object.c
	@${REINPLACE_CMD} -e \
		's|/usr/local/gtksql|${PREFIX}/lib/gtksql|' \
		${WRKSRC}/src/plugins.c

.include <bsd.port.mk>
