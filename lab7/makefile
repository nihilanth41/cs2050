CC=gcc
CFLAGS=-I.
DEPS = set.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runner: runner.o set.o 
	gcc -o runner runner.o set.o -I.
