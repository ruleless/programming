commdir:=../../../common
incdir:=$(commdir)
srcdir:=$(incdir)

cc:=g++
VPATH:=$(srcdir)
CXXFLAGS:=-g -Wall -lpthread -I $(subst :, -I,$(incdir))

.PHONY:all clean
all:sample1 sample2 sample3 cat

sample1:sample1.o common.o
	$(cc) sample1.o common.o -o sample1 $(CXXFLAGS)
sample2:sample2.o common.o
	$(cc) -o sample2 sample2.o common.o $(CXXFLAGS)
sample3:sample3.o common.o
	$(cc) -o sample3 sample3.o common.o $(CXXFLAGS)
cat:cat.o common.o
	$(cc) -o cat cat.o common.o $(CXXFLAGS)

common.o:common.cpp common.h
	$(cc) -c $(commdir)/common.cpp

sample1.o:sample1.cpp
	$(cc) -c sample1.cpp $(CXXFLAGS)
sample2.o:sample2.cpp
	$(cc) -c sample2.cpp $(CXXFLAGS)
sample3.o:sample3.cpp
	$(cc) -c sample3.cpp $(CXXFLAGS)
cat.o:cat.cpp

clean:
	-rm sample1 sample2 sample3 cat *.o
