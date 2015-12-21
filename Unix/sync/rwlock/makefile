common_dir:=../../common
inc_dir:=$(common_dir)
src_dir:=$(inc_dir)

cc:=g++ -std=c++11
VPATH:=$(src_dir)

CXXFLAGS:=-g -Wall -lpthread -I $(subst :, -I,$(inc_dir))

.PHONY:all clean

all:test

test:test.o rwlock.o common.o
	$(cc) -o test $^ $(CXXFLAGS)

test.o:test.cpp
rwlock.o:rwlock.cpp rwlock.h
common.o:common.cpp common.h

clean:
	-rm *.o test
