# packr - hybrid package manager
# See LICENSE file for more information

# Compiler
CC="gcc"

VER = 0.1-dev

PREFIX = /usr

#INCS =
#LIBS =

CFLAGS = -march=native -O2 -lX11 ${INCS}
LDFLAGS = ${LIBS} -g
