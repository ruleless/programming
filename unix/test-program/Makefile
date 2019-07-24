COMMON_DIR:=../common

CC:=clang++
CXX:=clang++
CXXFLAGS:=-g -Wall -I $(subst :, -I,$(COMMON_DIR))
VPATH:= $(COMMON_DIR)
LDFLAGS:=

targets:=timeex schedule

.PHONY:all clean install remove

all:$(targets)

timeex:timeex.o common.o
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)
schedule:schedule.o common.o
	$(CC) -o $@ $^ $(CXXFLAGS) $(LDFLAGS)

timeex.o:timeex.cpp
common.o:common.cpp common.h

install:
	-cp $(targets) /usr/local/bin
remove:
	-rm $(foreach v,$(targets),/usr/local/bin/$(v))
clean:
	-rm *.o $(targets)
