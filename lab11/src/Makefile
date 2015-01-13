IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -g -W -lm

ODIR=obj
LDIR =../lib

_DEPS = parser.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = parser.o frontend.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

frontend: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
