commdir:=../../common
incdir:=$(commdir)
srcdir:=$(incdir)

cc=g++
VPATH=$(srcdir)
CFLAGS=-g -Wall -I $(subst :, -I, $(incdir))

objs:=cat.o common.o

.PHONY:all clean
all:cat
cat:$(objs)
	$(cc) $(objs) -o cat $(CFLAGS)
cat.o:cat.cpp
	$(cc) -c cat.cpp -o cat.o $(CFLAGS)
common.o:common.cpp common.h
	$(cc) -c $(commdir)/common.cpp -o common.o $(CFLAGS)

clean:
	-rm $(objs) cat
