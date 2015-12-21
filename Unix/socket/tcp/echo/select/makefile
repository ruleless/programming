
VPATH=../../../commonw
DIR_INC=../../../common

all:server client
.PHONY:all

#生成服务器程序
server:server.o
	g++ -o server server.o -g

server.o:server.cpp
	g++ -c server.cpp -I $(DIR_INC)


#生成客户端程序
client:client.o
	g++ -o client client.o -g

client.o:client.cpp
	g++ -c client.cpp


#清理
.PHONY:clean
clean:
	-rm *.o client server
