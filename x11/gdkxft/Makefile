# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdkxft
PORTVERSION=	1.5
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-aliased font support for gtk+

LIB_DEPENDS=	libXft.so:${PORTSDIR}/x11-fonts/libXft
LIB_DEPENDS+=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
LIB_DEPENDS+=	libfreetype.so:${PORTSDIR}/print/freetype2

USE_GNOME=	gtk12
USES=		iconv pkgconfig libtool gettext
USE_XORG+=	x11 xft
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CFLAGS+=	`pkg-config xft --cflags`
CONFIGURE_ARGS=	--sbindir=${PREFIX}/bin \
		--without-gnome
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config --prefix|$$GTK_CONFIG --prefix|g ; \
		 s|libgdk.la|libgdk-12.so|g ; \
		 s|libgdk.so|libgdk-12.so|g ; \
		 s|GDK_DLOPEN_NAME=.*$$|GDK_DLOPEN_NAME="libgdk-12.so"|g' \
			${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|src capplet|src @BUILD_CAPPLET_TRUE@capplet|g ; \
		 s|DESTDIR)\$$(datadir|DESTDIR)\$$(pkgdatadir|g ; \
		 s|la_LDFLAGS =.*$$|la_LDFLAGS = -module -avoid-version|g'
.for file in gdkxft_sysinstall.in gdkxft.c generate.pl
	@${REINPLACE_CMD} -e 's|gtk-config |${GTK_CONFIG:T} |g' \
	  ${WRKSRC}/src/${file}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdkxft.so

.include <bsd.port.mk>
