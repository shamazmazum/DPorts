# Created by: Max Khon <fjoe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libiqxmlrpc
PORTVERSION=	0.12.4
PORTREVISION=	3
CATEGORIES=	devel net
MASTER_SITES=	SF

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Free, object-oriented XML-RPC implementation written in C++

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=

DOCS_BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
DOCS_CMAKE_ARGS_OFF=	-Dbuild_docs=off

LICENSE=	BSD

USE_GNOME=	libxml2
USES=		cmake tar:bzip2
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

PORTDOCS=	*

post-patch:
	${REINPLACE_CMD} -e 's,lib/pkgconfig,libdata/pkgconfig,' ${WRKSRC}/libiqxmlrpc/CMakeLists.txt
	${REINPLACE_CMD} -e 's,share/doc/libiqxmlrpc-$${Libiqxmlrpc_VERSION},${DOCSDIR_REL},' ${WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
