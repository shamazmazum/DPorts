# Created by: Borja Lopez<borja@pexego.es>
# $FreeBSD$

PORTNAME=	openerp-web
PORTVERSION=	5.0.11
PORTREVISION=	1
CATEGORIES=	finance python
MASTER_SITES=	http://openerp.com/download/stable/source/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	borja@pexego.es
COMMENT=	OpenERP Web Client

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>0:${PORTSDIR}/www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}Babel>0:${PORTSDIR}/devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}beaker>0:${PORTSDIR}/www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}simplejson>0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}formencode>0:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}parsing>0:${PORTSDIR}/devel/py-parsing \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}xlwt>0:${PORTSDIR}/textproc/py-xlwt
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

USE_RC_SUBR=	openerp-web

WRKSRC=		${WRKDIR}/openerp-web-${PORTVERSION}

post-install:
	@${INSTALL_DATA} ${FILESDIR}/openerp-web.conf ${STAGEDIR}${PREFIX}/etc/openerp-web.conf.sample
	@${INSTALL_SCRIPT} ${FILESDIR}/openerp-web.wrapper ${STAGEDIR}${PREFIX}/bin/openerp-web
	@${MKDIR} ${STAGEDIR}${PREFIX}/openerp-web
	@${INSTALL_SCRIPT} ${FILESDIR}/openerp-web.py ${STAGEDIR}${PREFIX}/openerp-web/openerp-web.py

.include <bsd.port.mk>
