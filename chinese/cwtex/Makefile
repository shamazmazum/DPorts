# Created by: Shen Chuan-Hsing
# $FreeBSD$

PORTNAME=	cwtex
PORTVERSION=	16.6
PORTREVISION=	6
CATEGORIES=	chinese
MASTER_SITES=	http://ftp.ussg.iu.edu/FreeBSD/distfiles/ \
		http://ftp.nara.wide.ad.jp/pub/FreeBSD/distfiles/
DISTFILES=	cwtexmain.tgz cwtexbin-${PORTVERSION}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CwTeX let you use Chinese Big5 codes in TeX/LaTeX documents

USE_TEX=	latex
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKSRC}/share ${WRKSRC}/bin
	${TAR} -kxzf ${DISTDIR}/cwtexmain.tgz -C ${WRKSRC}/share
	${TAR} -kxzf ${DISTDIR}/cwtexbin-${PORTVERSION}.tgz -C ${WRKSRC}/bin

do-install:
	cd ${WRKSRC}/share && ${FIND} * \
		| ${CPIO} -dpum --quiet -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${CAT} ${FILESDIR}/config.ps >> ${PSFONTSMAP}
	mktexlsr

.include <bsd.port.pre.mk>

PSFONTSMAP!=	${LOCALBASE}/bin/kpsewhich -format 'dvips config' config.ps 2>/dev/null || ${ECHO_CMD} "/dev/null"

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>
