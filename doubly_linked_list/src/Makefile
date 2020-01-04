IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = dll.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = dll.o application.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

application: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
	
clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
