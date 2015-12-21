commdir:=../../../common
incdir:=$(commdir)
srcdir:=$(incdir)

cc:=g++
VPATH:=$(srcdir)
CXXFLAGS:=-g -Wall -lpthread -I $(subst :, -I,$(incdir))

.PHONY:all clean
all:sample1 sample2

sample1:sample1.o common.o
	$(cc) -o sample1 sample1.o common.o $(CXXFLAGS)
sample2:sample2.o common.o
	$(cc) -o sample2 sample2.o common.o $(CXXFLAGS)

sample1.o:sample1.cpp SampleDef.h
common.o:common.h common.cpp

clean:
	-rm *.o sample1 sample2
