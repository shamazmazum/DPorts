# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	1.3.110
CATEGORIES=	games python
MASTER_SITES=	SF/fretsonfire/fretsonfire/${PORTVERSION}
PKGNAMEPREFIX=	fretsonfire-
DISTNAME=	${PKGNAMEPREFIX:S/f/F/g:S/o/O/}${PORTVERSION}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Frets on Fire data files

NO_BUILD=	yes
DATADIR=	share/${PKGNAMEPREFIX:S/-//}
RESTRICTED=	Only Unreal Voodoo site is allowed to distribute the music
WRKSRC=		${WRKDIR}/Frets\ on\ Fire-${PORTVERSION}

EXTRACT_AFTER_ARGS=	--exclude 'win32' "Frets on Fire-${PORTVERSION}/${PORTNAME}"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DATADIR}
	@cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${PREFIX}/${DATADIR}/{}" \;

.include <bsd.port.mk>
