# Created by: Yinghong.Liu <liu_yinghong@yahoo.com.cn>
# $FreeBSD$

PORTNAME=	gmimms
DISTVERSION=	0.0.9
PORTREVISION=	6
CATEGORIES=	multimedia net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER= ports@FreeBSD.org
COMMENT=	Frontend to MiMMS (Multimedia Stream ripper)

RUN_DEPENDS=	mimms:${PORTSDIR}/multimedia/mimms

USES=		pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--disable-nls
INSTALL_TARGET=	install-exec

PLIST_FILES=	bin/gmimms

PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL NEWS README

DESKTOP_ENTRIES=	"GIMMS" \
			"Multimedia Stream ripper" \
			"" \
			"gmimms" \
			"GTK;AudioVideo;Network;" \
			"false"

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
