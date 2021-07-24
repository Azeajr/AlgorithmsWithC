MAKNAM = stackTest.mak

LIBDRS =

INCDRS = -I $(ALGOWC_TOPDIR)/include

LIBFLS =

SRCFLS = stackTest.c\
		$(ALGOWC_TOPDIR)/src/stack.c\
		$(ALGOWC_TOPDIR)/src/list.c

OBJFLS = stackTest.o\
		$(ALGOWC_TOPDIR)/src/stack.o\
		$(ALGOWC_TOPDIR)/src/list.o

EXE = stackTest.out

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