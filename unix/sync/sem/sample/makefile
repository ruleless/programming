commdir:=../../../snail/lib/common:../../../snail/lib
incdir:=$(commdir)
srcdir:=$(incdir)

cc:=g++
VPATH:=$(srcdir)
CXXFLAGS:=-g -Wall -lpthread -I $(subst :, -I,$(incdir))

.PHONY:all clean
all:semcreate semunlink semgetval semwait sempost

semcreate:semcreate.o common.o
	$(cc) -o semcreate semcreate.o common.o $(CXXFLAGS)
semunlink:semunlink.o common.o
	$(cc) -o semunlink semunlink.o common.o $(CXXFLAGS)
semgetval:semgetval.o common.o
	$(cc) -o semgetval semgetval.o common.o $(CXXFLAGS)
semwait:semwait.o common.o
	$(cc) -o semwait semwait.o common.o $(CXXFLAGS)
sempost:sempost.o common.o
	$(cc) -o sempost sempost.o common.o $(CXXFLAGS)

semcreate.o:semcreate.cpp semdef.h
common.o:common.cpp common.h
semgetval.o:semgetval.cpp semdef.h
semwait.o:semwait.cpp semdef.h
sempost.o:sempost.cpp semdef.h

clean:
	-rm *.o semcreate semunlink semgetval semwait sempost
