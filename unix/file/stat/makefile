commdir:=../../common
incdir:=$(commdir)
srcdir:=$(incdir)

cc=g++
VPATH=$(srcdir)
CFLAGS=-g -Wall -I $(subst :, -I, $(incdir))

objs:=fstat.o

.PHONY:all clean
all:fstat
fstat:$(objs)
	$(cc) $(objs) -o fstat $(CFLAGS)
fstat.o:fstat.cpp
	$(cc) -c fstat.cpp -o fstat.o $(CFLAGS)

clean:
	-rm $(objs) fstat
