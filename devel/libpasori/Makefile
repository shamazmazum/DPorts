# Created by: Yoshihiko Sarumaru <mistral@imasy.or.jp>
# $FreeBSD$

PORTNAME=	libpasori
PORTVERSION=	02
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	${PORTNAME}/20457
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	sarumaru@jp.FreeBSD.org
COMMENT=	FeliCa read/write library for Sony RC-S320 USB FeliCa R/W(PaSoRi)

USES=	tar:bzip2
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/lib ${WRKSRC}/lpdump ${WRKSRC}/lptest
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
.if ${OSVERSION} < 800069
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/lib/Makefile
.else
	@${CP} ${FILESDIR}/Makefile.lib.usb20 ${WRKSRC}/lib/Makefile
.endif
	@${CP} ${FILESDIR}/Makefile.lpdump ${WRKSRC}/lpdump/Makefile
	@${CP} ${FILESDIR}/Makefile.lptest ${WRKSRC}/lptest/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
