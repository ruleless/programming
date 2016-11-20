
cc:=g++
IncludeDir:=../../common/:../common/ #头文件目录
SourceDir:=$(IncludeDir)			 #源文件目录
Options:=-Wall -g -I $(subst :, -I,$(IncludeDir)) -lpthread
CFLAGS:=$(Options)
CXXFLAGS:=$(Options)

VPATH:=$(SourceDir)				#源文件搜索目录

objs:=test.o PrintTID.o common.o Thread.o

.PHONY:all
all:main

main:$(objs)
	$(cc) $(objs) -o main $(Options)
test.o:test.cpp
	$(cc) -c test.cpp -o test.o $(Options)
PrintTID.o:PrintTID.cpp
	$(cc) -c PrintTID.cpp -o PrintTID.o $(Options)

.PHONY:clean
clean:
	-rm objs
