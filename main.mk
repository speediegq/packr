# packr - hybrid package manager
# See LICENSE file for more information

# Compiler
CC="gcc"

VER = 0.1-dev

PREFIX = /usr

#INCS =
#LIBS =

CPPFLAGS = -DVERSION=\"${VER}\"
CFLAGS   = -march=native -O2 -lX11 ${INCS} ${CPPFLAGS}
LDFLAGS  = ${LIBS} -g
