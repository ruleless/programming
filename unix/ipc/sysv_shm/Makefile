COMMON_DIR:=../..:../../common

CC:=clang++
CXX:=clang++
CXXFLAGS:=-g -Wall -I $(subst :, -I,$(COMMON_DIR))
VPATH:= $(COMMON_DIR)
LDFLAGS:= -lrt

all: exe

exe:shmget shmrm shmwrite shmread

shmget:shmget.o common.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmrm:shmrm.o common.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmwrite:shmwrite.o common.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmread:shmread.o common.o
	$(CXX) $^ $(LDFLAGS) -o $@

shmget.o:shmget.cpp shmdef.h
shmrm.o:shmrm.cpp shmdef.h
shmwrite.o:shmwrite.cpp shmdef.h
shmread.o:shmread.cpp shmdef.h

common.o:common.cpp common.h

clean:
	-rm *.o shmget shmrm shmwrite shmread
