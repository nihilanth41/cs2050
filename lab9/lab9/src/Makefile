IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -g -W -lm

ODIR=obj
LDIR =../lib

_DEPS = bst.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = bst.o runner.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

runner: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
