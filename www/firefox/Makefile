# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	30.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		https://ftp.mozilla.org/pub/mozilla.org/${PORTNAME}/candidates/${DISTVERSION}-candidates/build2/source/
DISTNAME=	${PORTNAME}-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.10.3:${PORTSDIR}/devel/nspr \
		nss>=3.16:${PORTSDIR}/security/nss \
		soundtouch>=1.7.0:${PORTSDIR}/audio/soundtouch \
		harfbuzz>=0.9.25:${PORTSDIR}/print/harfbuzz \
		graphite2>=1.2.4:${PORTSDIR}/graphics/graphite2 \
		libvorbis>=1.3.4:${PORTSDIR}/audio/libvorbis \
		opus>=1.1:${PORTSDIR}/audio/opus \
		libvpx>=1.3.0:${PORTSDIR}/multimedia/libvpx \
		sqlite3>=3.8.3.1:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
#		cairo>=1.12.16,2:${PORTSDIR}/graphics/cairo \

LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

USE_AUTOTOOLS=	autoconf213:env
USE_PYTHON_BUILD=2
OBJDIR_BUILD=	# in-tree build broken after bug 789837
USE_GECKO=	gecko
CONFLICTS=	firefox-esr-24.* firefox-esr-17.* firefox-1[07].*
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	-cairo
MOZILLA_NAME=	Firefox

WANT_GNOME=	yes
USE_QT5=	# empty
QT_NONSTANDARD=	yes
ALL_TARGET=	default
GNU_CONFIGURE=	yes
USE_GL=		gl
USES=		dos2unix tar:bzip2
DOS2UNIX_FILES=	media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp
NO_MOZPKGINSTALL=yes

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/' \
		--enable-application=browser \
		--enable-official-branding

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC:=	${WRKDIR}/mozilla-release

# avoid clang 3.2/3.3 crash in js/src/jsgc.cpp on refillFreeList<(js::AllowGC)1>
# http://svnweb.freebsd.org/changeset/base/255804
.if ${CHOSEN_COMPILER_TYPE} == clang && ${ARCH} == i386 && ${OSVERSION} < 1000056
. if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
BROKEN=		Cannot build with OPTIMIZED_CFLAGS option due to \
		a ${CHOSEN_COMPILER_TYPE} bug: unset the option or \
		use FAVORITE_COMPILER=gcc in Makefile.local/make.conf
# apply workaround only for -O2 or greater
. elif ${CXXFLAGS:M-O*} && ! ${CXXFLAGS:M-O[01]}
.  if ${MACHINE_CPU:Msse2}
CXXFLAGS+=	-msse2
.  else
CXXFLAGS+=	-O1
.  endif
. endif
.endif

.if ${PORT_OPTIONS:MALSA}
BUILD_DEPENDS+=	alsa-lib>=1.0.27.2_1:${PORTSDIR}/audio/alsa-lib
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
BUILD_DEPENDS+=	gstreamer1-libav>=1.2.4:${PORTSDIR}/multimedia/gstreamer1-libav
.endif


post-patch:
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${WRKSRC}/js/src/ && ${AUTOCONF})

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${FIREFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include <bsd.port.post.mk>
