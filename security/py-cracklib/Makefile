# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for cracklib

LICENSE=	LGPL21

LIB_DEPENDS=	libcrack.so:${PORTSDIR}/security/cracklib

MASTERDIR=	${.CURDIR}/../cracklib
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PYTHON_SLAVEPORT=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
	"{s#__version__ = '[^']*'#__version__ = '${PORTVERSION}'#;}" \
	${BUILD_WRKSRC}/*.py

.include "${MASTERDIR}/Makefile"
