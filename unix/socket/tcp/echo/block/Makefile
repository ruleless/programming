CC:= g++
CXX:= g++
LDFLAGS:=
RM:= rm -rf

all:client server

client:client.o
server:server.o

client.o:client.cpp
server.o:server.cpp

clean:
	-$(RM) *.o client server
