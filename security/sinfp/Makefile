# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sinfp
PORTREVISION=	${DBDATE}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Full operating system stack fingerprinting suite

LICENSE=	ART10

BUILD_DEPENDS=	p5-Net-SinFP>=2.02:${PORTSDIR}/security/p5-Net-SinFP
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST=		""
PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/${PORTNAME}.db
PLIST_DIRS=	%%DATADIR%%
NO_BUILD=	yes
MASTERDIR=	${.CURDIR}/../p5-Net-SinFP
DBDATE=		20110125

USES=		shebangfix
SHEBANG_FILES=	bin/${PORTNAME}.pl

post-patch:
	@${REINPLACE_CMD} -e 's!$$Bin/../db/!${DATADIR}/!' ${WRKSRC}/bin/${PORTNAME}.pl

do-install:
	${INSTALL} -d ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.ifdef DBDATE
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}-${DBDATE}.db ${STAGEDIR}${DATADIR}/${PORTNAME}.db
.else
	${INSTALL_DATA} ${WRKSRC}/bin/${PORTNAME}.db ${STAGEDIR}${DATADIR}/
.endif

.include "${MASTERDIR}/Makefile"
