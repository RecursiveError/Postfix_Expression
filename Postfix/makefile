CC = gcc
CFLAGS = -std=c11 -Wall
LD = gcc
BUILDDIR = build
LIBDIR = lib

all: $(BUILDDIR)/main clear

$(BUILDDIR)/main: main.o postfix.o stack.o cal_fix.o
	$(LD) $^ -o $@


main.o: src/main.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

stack.o: $(LIBDIR)/stack.c $(LIBDIR)/stack.h
	$(CC) $(CFLAGS) -c $< -o $@

postfix.o: $(LIBDIR)/postfix.c $(LIBDIR)/postfix.h
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

cal_fix.o: $(LIBDIR)/cal_fix.c $(LIBDIR)/cal_fix.h
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@
clear:
	rm -f *.o

.PHONY: clear