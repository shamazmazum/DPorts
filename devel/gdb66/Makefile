# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	6.6
PORTREVISION?=	2
CATEGORIES=	devel
MASTER_SITES=   ${MASTER_SITE_GNU:S,$,:gdb,}	\
		http://aldan.algebra.com/~mi/:gdbtk
MASTER_SITE_SUBDIR=gdb/:gdb
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:gdb

MAINTAINER=	mi@aldan.algebra.com
COMMENT?=	GNU GDB of newer version than comes with the system

PKGNAMESUFFIX=	66

OPTIONS_DEFINE=	INSIGHT
INSIGHT_DESC=	Tcl/Tk GUI (experimental!)

CONFLICTS?=	gdb-[7-9]*
USE_GCC=	any
USES=		gettext iconv gmake readline tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--disable-werror \
		--enable-target=all \
		--enable-tui ${ICONV_CONFIGURE_ARG}
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT
EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}
VER=		${PORTVERSION:S/.//}
PLIST_SUB=	VER=${VER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MINSIGHT}
PKGNAMESUFFIX=	-insight
USES+=		tk
LIB_DEPENDS=	libitk.so:${PORTSDIR}/x11-toolkits/itk
RUN_DEPENDS=	${LOCALBASE}/lib/iwidgets:${PORTSDIR}/x11-toolkits/iwidgets
DISTFILES+=	gdbtk-6.6${EXTRACT_SUFX}:gdbtk
PLIST_SUB+=	INSIGHT=''
EXTRA_PATCHES=	${FILESDIR}/itcl33-patch \
		${FILESDIR}/extra-gdb-gdbtk-generic-gdbtk.c \
		${FILESDIR}/extra-gdb-gdbtk-generic-gdbtk-hooks.c
CONFIGURE_ARGS+=--enable-gdbtk \
		--with-tclconfig=${TCL_LIBDIR} \
		--with-tclinclude=${TCL_INCLUDEDIR}/generic \
		--with-tkconfig=${TK_LIBDIR} \
		--with-tkinclude=${TK_INCLUDEDIR}/generic \
		--with-itclconfig=${LOCALBASE}/lib/itcl3.4 \
		--with-itkconfig=${LOCALBASE}/lib/itk3.3

pre-everything::
	#
	# The Tk-based GUI (Insight) is patched to work with [incr tcl]
	# version 3.3 and is currently experimental. Bug reports should
	# be accompanied by patches.
	#

pre-configure:
	${MKDIR} ${WRKSRC}/itcl/generic
	${LN} -s ${LOCALBASE}/include/itk3.3/*.h ${WRKSRC}/itcl/generic/
	${LN} -s ${LOCALBASE}/include/itcl3.4/*.h ${WRKSRC}/itcl/generic/
.else
PLIST_SUB+=	INSIGHT='@comment '
CONFLICTS+=	gdb-insight*
.endif

.for a in ia64 powerpc
BROKEN_${a}=	Does not configure on ia64 or powerpc
.endfor



do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${STAGEDIR}${PREFIX}/bin/gdb${VER}
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdbtui${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/gdb.1 ${STAGEDIR}${PREFIX}/man/man1/gdb${VER}.1
.if ${PORT_OPTIONS:MINSIGHT}
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/insight
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/redhat/gui
	${CP} -p ${WRKSRC}/libgui/library/*.tcl	\
		${WRKSRC}/libgui/library/tclIndex \
			${STAGEDIR}${PREFIX}/share/redhat/gui/
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/insight1.0
	${CP} -Rp ${WRKSRC}/gdb/gdbtk/library/*.tcl	\
		${WRKSRC}/gdb/gdbtk/library/*.itcl	\
		${WRKSRC}/gdb/gdbtk/library/*.ith	\
		${WRKSRC}/gdb/gdbtk/library/*.itb	\
		${WRKSRC}/gdb/gdbtk/library/help	\
		${WRKSRC}/gdb/gdbtk/library/images*	\
		${WRKSRC}/gdb/gdbtk/library/tclIndex	\
			${STAGEDIR}${PREFIX}/lib/insight1.0
.endif

.include <bsd.port.mk>
