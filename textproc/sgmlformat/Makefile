# Created by: jfieber
# $FreeBSD$

PORTNAME=	sgmlformat
PORTVERSION=	1.7
PORTREVISION=	4
CATEGORIES=	textproc print
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Generates groff and HTML from linuxdoc and docbook SGML documents

USES=		perl5
USE_PERL5=	run
MAKE_ENV=	STAGEDIR=${STAGEDIR}

# There are two ports that satisfy the nsgmls requirement.
# Jade is preferred.

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} != "i386"
WITH_OPENJADE=	yes
.endif

.if defined(WITH_OPENJADE)
RUN_DEPENDS=	onsgmls:${PORTSDIR}/textproc/openjade
.else
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/jade
.endif
RUN_DEPENDS+=	${LOCALBASE}/share/sgml/linuxdoc:${PORTSDIR}/textproc/linuxdoc \
		${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml
# Above depending on docbook-4.1 file is just for workaround.  We need
# some of docbook DTDs, but not all.

.if defined(WITH_OPENJADE)
post-patch:
	@${REINPLACE_CMD} -e 's,nsgmls,onsgmls,g' ${WRKSRC}/sgmlfmt/sgmlfmt.pl
	@${REINPLACE_CMD} -e 's,nsgmls,onsgmls,g' ${WRKSRC}/instant/traninit.c
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/sgml/transpec

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
