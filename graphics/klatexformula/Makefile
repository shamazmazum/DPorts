# $FreeBSD$

PORTNAME=	klatexformula
PORTVERSION=	3.2.8
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Convert LaTeX formula to image

BUILD_DEPENDS=	help2man:${PORTSDIR}/misc/help2man

USES=		cmake:outsource shared-mime-info
USE_QT4=	gui xml dbus designer_build linguist_build \
		qmake_build moc_build rcc_build uic_build
USE_TEX=	latex dvipsk
USE_GHOSTSCRIPT_RUN=	yes
CMAKE_ARGS=	-DQT_QMAKE_EXECUTABLE_FINDQT=${QMAKE} \
		-DKLF_BUILD_KTEXTEDITORPLUGIN=off \
		-DKLF_INSTALL_POST_UPDATEMIMEDATABASE=off \
		-DKLF_INSTALL_SHARE_MAN1_DIR=man/man1
CXXFLAGS=	-I${LOCALBASE}/include

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
