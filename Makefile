NAME = packr
HEAD = src/main.h
SRC  = src/${NAME}.c src/${NAME}.h

include main.mk

default: ${NAME}

src/${NAME}.o: src/${NAME}.c $(HEAD)
	${CC} -c src/${NAME}.c -o src/${NAME}.o

${NAME}: src/${NAME}.o
	${CC} src/${NAME}.o -o src/${NAME} ${LDFLAGS}

clean:
	rm -f src/${NAME}.o
	rm -f src/${NAME}
	@echo "Cleaned."

install: all
	[ -f src/${NAME} ] && cp -f src/${NAME} ${DESTDIR}${PREFIX}/bin || :
	[ -f src/${NAME} ] && chmod +x ${DESTDIR}${PREFIX}/bin/${NAME} || :
	@echo "Installed."

dist: clean
	mkdir -p packr-${VER}
	cp src/ doc/ *.mk Makefile LICENSE README.md packr-${VER}
	tar -cf packr-${VER}.tar packr-${VER}
	gzip packr-${VER}.tar
	rm -rf packr-${VER}
	@echo "Created packr-${VER}.tar.gz"

.PHONY: clean all install dist default
