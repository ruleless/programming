commdir:=../../common:../../common/algorithm
incdir:=$(commdir)
srcdir:=$(incdir)

cc:=g++
VPATH:=$(srcdir)
CFLAGS:=-g -Wall -I $(subst :, -I,$(srcdir))

.PHONY:all clean
all:QueueTest StackTest

QueueTest:QueueTest.o
	$(cc) -o QueueTest QueueTest.o $(CFLAGS)
QueueTest.o:QueueTest.cpp Queue.h
	$(cc) -c QueueTest.cpp $(CFLAGS)

StackTest:StackTest.o
	$(cc) -o StackTest StackTest.o $(CFLAGS)
StackTest.o:StackTest.cpp Stack.h
	$(cc) -c StackTest.cpp $(CFLAGS)

clean:
	-rm QueueTest QueueTest.o StackTest StackTest.o
