MAKNAM = coverTest.mak

LIBDRS =

INCDRS = -I $(ALGOWC_TOPDIR)/include

LIBFLS =

SRCFLS = coverTest.c\
		$(ALGOWC_TOPDIR)/src/cover.c\
		$(ALGOWC_TOPDIR)/src/list.c\
		$(ALGOWC_TOPDIR)/src/set.c

OBJFLS = coverTest.o\
		$(ALGOWC_TOPDIR)/src/cover.o\
		$(ALGOWC_TOPDIR)/src/list.o\
		$(ALGOWC_TOPDIR)/src/set.o

EXE = coverTest.out

CC = c89
LL = c89
CFLAGS =-Wall -g
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
