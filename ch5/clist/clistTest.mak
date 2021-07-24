MAKNAM = clistTest.mak

LIBDRS =

INCDRS = -I $(ALGOWC_TOPDIR)/include

LIBFLS =

SRCFLS = clistTest.c\
		$(ALGOWC_TOPDIR)/src/clist.c

OBJFLS = clistTest.o\
		$(ALGOWC_TOPDIR)/src/clist.o

EXE = clistTest.out

CC = c89
LL = c89
CFLAGS =
LFLAGS =

$(EXE): $(OBJFLS)
		$(LL) $(LFLAGS) -o $@ $(OBJFLS) $(LIBDRS) $(LIBFLS)

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