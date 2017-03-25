commdir:=../../common
incdir:=$(commdir)
srcdir:=$(incdir)

cc:=g++
VPATH:=$(srcdir)
CFLAGS:=-g -Wall -I $(subst :, -I,$(incdir))

objs:=dir.o common.o

.PHONY:all clean install
all:dir
dir:$(objs)
	$(cc) -o dir $(objs) $(CFLAGS)
dir.o:dir.cpp
	$(cc) -c dir.cpp $(CFLAGS)
common.o:common.cpp common.h
	$(cc) -c $(commdir)/common.cpp $(CFLAGS)

install:
	-cp dir /usr/local/bin
clean:
	-rm $(objs) dir
