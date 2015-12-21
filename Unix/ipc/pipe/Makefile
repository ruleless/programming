CC:=clang++
CXX:=clang++
CXXFLAGS:=-g -Wall

all:client server

client:client.o common.o
	$(CXX) -o $@ $^
server:server.o common.o
	$(CXX) -o $@ $^

client.o:client.cpp common.h
server.o:server.cpp common.h
common.o:common.cpp common.h

clean:
	rm *.o client server
