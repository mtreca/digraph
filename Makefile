CC = gcc
CFLAGS  = -pedantic -Wall -Wextra

PREFIX = /usr/local

PROG = digraph

all: $(PROG)

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) -o $(PROG) $(PROG).c

clean:
	$(RM) $(PROG)

install: $(PROG)
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp $(PROG) ${DESTDIR}${PREFIX}/bin/$(PROG)
	chmod 755 ${DESTDIR}${PREFIX}/bin/$(PROG)

uninstall:
	rm ${DESTDIR}${PREFIX}/bin/$(PROG)

