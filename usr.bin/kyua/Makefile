# $FreeBSD$

KYUA_SRCDIR=	${SRCTOP}/contrib/subrepo-kyua
.PATH: ${KYUA_SRCDIR}

.if ${MACHINE_ARCH} != "mips64"
# FIXME: doesn't work as a purecap binary yet
WANT_COMPAT=	64
.include <bsd.compat.mk>
.else
WANT_CHERI=none
.endif

PROG_CXX=	kyua
SRCS=		main.cpp
LIBADD=		kyua_cli kyua_drivers kyua_engine kyua_model kyua_store

MAN=		kyua-about.1 \
		kyua-config.1 \
		kyua-db-exec.1 \
		kyua-db-migrate.1 \
		kyua-debug.1 \
		kyua-help.1 \
		kyua-list.1 \
		kyua-report-html.1 \
		kyua-report-junit.1 \
		kyua-report.1 \
		kyua-test.1 \
		kyua.1 \
		kyua.conf.5 \
		kyuafile.5

CFLAGS+=	-I${KYUA_SRCDIR}

# kyua uses auto_ptr
CFLAGS+=	-Wno-deprecated-declarations

FILESGROUPS=	DOCS EXAMPLES MISC STORE

CONFS=		kyua.conf
CONFSDIR=	${KYUA_CONFDIR}

DOCS=		AUTHORS CONTRIBUTORS LICENSE
DOCSDIR=	${KYUA_DOCDIR}

EXAMPLES=	Kyuafile.top kyua.conf
EXAMPLESDIR=	${KYUA_EGDIR}
.PATH:		${KYUA_SRCDIR}/examples

MISC=		context.html index.html report.css test_result.html
MISCDIR=	${KYUA_MISCDIR}
.PATH:		${KYUA_SRCDIR}/misc

STORE=		migrate_v1_v2.sql migrate_v2_v3.sql schema_v3.sql
STOREDIR=	${KYUA_STOREDIR}
.PATH:		${KYUA_SRCDIR}/store

CLEANFILES+=	${MAN}
.PATH: ${SRCTOP}/contrib/subrepo-kyua/doc
.for man in ${MAN}
${man}: ${man}.in
	sh ${KYUA_SRCDIR}/doc/manbuild.sh \
	    -v "CONFDIR=${KYUA_CONFDIR}" \
	    -v "DOCDIR=${KYUA_DOCDIR}" \
	    -v "EGDIR=${KYUA_EGDIR}" \
	    -v "MISCDIR=${KYUA_MISCDIR}" \
	    -v "PACKAGE=kyua" \
	    -v "STOREDIR=${KYUA_STOREDIR}" \
	    -v "TESTSDIR=${TESTSBASE}" \
	    -v "VERSION=${KYUA_VERSION}" \
	    ${.ALLSRC} ${.TARGET}
.endfor

.include "${SRCTOP}/lib/kyua/Makefile.kyua"
.include <bsd.prog.mk>
