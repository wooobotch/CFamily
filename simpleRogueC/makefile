CC = gcc

COMPF = -x c

CFLAGS = -lncurses -I$(INCDIR)

INCDIR = ./include/

SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: rogue run clean

rogue:
	$(CC) $(COMPF)  $(SOURCES) $(CFLAGS) -o $@

run:
	./rogue

clean:
	rm rogue
