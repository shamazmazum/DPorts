# Created by: Max Khon
# $FreeBSD$

PORTNAME=	hpt
PORTVERSION=	1.2.4
PORTREVISION=	2
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/${PORTNAME}/1.2-release
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Highly Portable Tosser (full-featured FTN tosser)

LIB_DEPENDS=	libfidoconfig.so:${PORTSDIR}/news/husky-fidoconf

CONFLICTS=	husky-hpt-devel-[0-9]*

.if !defined(WITHOUT_PERL)
MAKE_ARGS+=	PERL=1
USES=		perl5
.else
MAKE_ARGS+=	PERL=0
.endif

USES+=		makeinfo
MAN1=		hpt.1 hptlink.1 hpttree.1 txt2pkt.1
MANCOMPRESSED=	yes
INFO=		hpt

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's^/path/to/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hptlink.1
	@${REINPLACE_CMD} -e 's^/some/path/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/hpttree.1
	@${REINPLACE_CMD} -e 's^/fido/etc/config^${PREFIX}/etc/fido/config^' \
		${WRKSRC}/man/txt2pkt.1

post-build:
	@cd ${WRKSRC}/doc && ${MAKE_CMD} ${MAKE_ARGS} all

post-install:
	@cd ${WRKSRC}/doc && ${MAKE_CMD} ${MAKE_ARGS} install

.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
