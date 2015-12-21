commdir:=../../../common
incdir:=$(commdir)

VPATH:=$(incdir)

cc:=g++
CXXFLAGS:=-g -Wall -lpthread -lrt -I $(subst :, -I,$(incdir))

.PHONY:all clean
all:client server

client:client.o common.o
	$(cc) -o client $^ $(CXXFLAGS)
server:server.o common.o
	$(cc) -o server $^ $(CXXFLAGS)

client.o:client.cpp shmdef.h
server.o:server.cpp shmdef.h
common.o:common.cpp

clean:
	-rm *.o client server
