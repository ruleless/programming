SNAIL_ROOT:=../snail
SNAIL_INC:=../snail/include
SNAIL_LIB:=$(SNAIL_ROOT)/lib/libsnail.a

INC_DIR:=$(SNAIL_INC)

CC:=clang++
CXX:=clang++
CXXFLAGS:=-g -Wall -I $(subst :, -I,$(INC_DIR))
LDFLAGS:=-L $(SNAIL_ROOT)/lib -lsnail

targets:=timeex schedule

.PHONY:all clean install remove

all:$(SNAIL_LIB) $(targets)

$(SNAIL_LIB):
	cd $(SNAIL_ROOT) && $(MAKE)

timeex:timeex.o
	$(CC) -o timeex timeex.o $(CXXFLAGS) $(LDFLAGS)
schedule:schedule.o
	$(CC) -o schedule schedule.o $(CXXFLAGS) $(LDFLAGS)

timeex.o:timeex.cpp
common.o:common.cpp common.h

install:
	-cp $(targets) /usr/local/bin
remove:
	-rm $(foreach v,$(targets),/usr/local/bin/$(v))
clean:
	-rm *.o $(targets)
