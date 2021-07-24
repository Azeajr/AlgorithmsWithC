MAKNAM = queueTest.mak

LIBDRS =

INCDRS = -I $(ALGOWC_TOPDIR)/include

LIBFLS =

SRCFLS = queueTest.c\
		$(ALGOWC_TOPDIR)/src/queue.c\
		$(ALGOWC_TOPDIR)/src/list.c

OBJFLS = queueTest.o\
		$(ALGOWC_TOPDIR)/src/queue.o\
		$(ALGOWC_TOPDIR)/src/list.o

EXE = queueTest.out

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

clean :
		-rm $(EXE)
		-rm $(OBJFLS)