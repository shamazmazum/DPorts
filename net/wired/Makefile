# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	wired
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://mirror.mcx2.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wired server

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir="${LOCALBASE}/lib" --includedir="${LOCALBASE}/include"
USES=		gmake
USE_RC_SUBR=	wired

MAN1=		wiredctl.1
MAN5=		wired.conf.5
MAN8=		wired.8

NO_STAGE=	yes
pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.for i in etc/wired.conf etc/resolv.conf banlist groups news users
	@if [ ! -f ${PREFIX}/wired/${i} ]; then \
		${CP} -p ${PREFIX}/wired/${i}.sample ${PREFIX}/wired/${i} ; \
	fi
.endfor
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
