# Created by: Roger Hardiman <roger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openh323
PORTVERSION=	1.19.0.1
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-v${PORTVERSION:S/./_/g}-src
EXTRACT_SUFX=	-tar.gz
DIST_SUBDIR=	openh323

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H323 Video Conferencing library

LIB_DEPENDS=	libpt_r.so:${PORTSDIR}/devel/pwlib

WRKSRC=		${WRKDIR}/${PORTNAME}_v${PORTVERSION:S/./_/g}

USES=		bison gmake
USE_GCC=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

ALL_TARGET=	optshared
CONFIGURE_ENV+=	BUILDTIME="YES"
CPPFLAGS+=	-I${LOCALBASE}/include -I${WRKSRC}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	BUILDTIME="YES"

OPTIONS_DEFINE=		FFMPEG SPEEX
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--enable-rfc2190avcodec=${LOCALBASE}/include/ffmpeg

SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ON=	--enable-localspeex=no
SPEEX_CONFIGURE_OFF=	--enable-localspeex=yes

.include <bsd.port.pre.mk>

.if (${ARCH} == "x86_64") || (${ARCH} == "ia64") || (${ARCH} == "powerpc") || (${ARCH} == "sparc64")
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/configure.ac

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libh323_r.so.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pwlib/codecs/audio/*.so

.include <bsd.port.post.mk>
