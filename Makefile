CC = gcc
CFLAGS  = -pedantic -Wall -Wextra

PROG = digraph

all: $(PROG)

$(PROG): $(PROG).c
	$(CC) $(CFLAGS) -o $(PROG) $(PROG).c

clean:
	$(RM) $(PROG)
