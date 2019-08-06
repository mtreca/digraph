CC = gcc
CFLAGS  = -pedantic -Wall -Wextra

PREFIX = /usr/
MANPREFIX = /usr/share/man

all: $(PROG)

digraph: digraph.c
	$(CC) $(CFLAGS) -o digraph digraph.c

clean:
	$(RM) digraph

install: digraph
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp digraph ${DESTDIR}${PREFIX}/bin/digraph
	chmod 755 ${DESTDIR}${PREFIX}/bin/digraph
	mkdir -p ${DESTDIR}${MANPREFIX}/man1/
	cp -f digraph.1 ${DESTDIR}${MANPREFIX}/man1/

uninstall:
	rm ${DESTDIR}${PREFIX}/bin/digraph
	rm -f ${DESTDIR}${MANPREFIX}/man1/digraph.1

