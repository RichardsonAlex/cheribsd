# $FreeBSD$

LIB_CXX=	lutok
INTERNALLIB=

LIBADD=		lua

.PATH: ${SRCTOP}/contrib/subrepo-lutok
SRCS=	c_gate.cpp		\
	debug.cpp		\
	exceptions.cpp		\
	operations.cpp		\
	stack_cleaner.cpp	\
	state.cpp

CFLAGS+=	-I${SRCTOP}/contrib/subrepo-lutok/include \
		-I${SRCTOP}/lib/liblua	\
		-I${SRCTOP}/contrib/lua/src

WARNS?=	3
SHLIB_MAJOR=	0

# lutok uses auto_ptr
CFLAGS+=	-Wno-deprecated-declarations

.include <bsd.lib.mk>
