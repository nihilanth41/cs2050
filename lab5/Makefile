CC=gcc
CFLAGS=-I.
DEPS = function.h
#rule states that .o files depend on .c files and deps(.h)
%.o: %.c $(DEPS)

runner: runner.o function.o
	$(CC) -o runner runner.o function.o -I.

