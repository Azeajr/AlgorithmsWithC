MAKNAM = setTest.mak

LIBDRS =

INCDRS = -I $(ALGOWC_TOPDIR)/include

LIBFLS =

SRCFLS = setTest.c\
		$(ALGOWC_TOPDIR)/src/list.c\
		$(ALGOWC_TOPDIR)/scr/set.c

OBJFLS = setTest.o\
		$(ALGOWC_TOPDIR)/src/list.o\
		$(ALGOWC_TOPDIR)/src/set.o

EXE = setTest.out

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
