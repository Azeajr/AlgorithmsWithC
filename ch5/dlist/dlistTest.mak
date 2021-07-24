MAKNAM = dlistTest.mak

LIBDRS =

INCDRS = -I $(ALGOWC_TOPDIR)/include

LIBFLS =

SRCFLS = dlistTest.c\
		$(ALGOWC_TOPDIR)/src/dlist.c

OBJFLS = dlistTest.o\
		$(ALGOWC_TOPDIR)/src/dlist.o

EXE = dlistTest.out

CC = c89
LL = c89
CFLAGS =
LFLAGS =

$(EXE): $(OBJFLS)
		$(LL) $(LFLAGS) -o $@ $(OBJFLS) $(LIBDRS)

.c.o:
		$(CC) $(CFLAGS) -o $@ -c $(INCDRS) $<

all:
		make -f $(MAKNAM) clean
		make -f $(MAKNAM) depend

depend:
		makedepend $(INCDRS) -f $(MAKNAM) $(SRCFLS)
		make -f $(MAKNAM) $(EXE)

clean:
		-rm $(EXE)
		-rm $(OBJFLS)