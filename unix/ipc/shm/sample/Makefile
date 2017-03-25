COMMON_DIR:=../../../common/

CXXFLAGS:=-g -Wall -I $(subst :, -I,$(COMMON_DIR))
VPATH:= $(COMMON_DIR)
LDFLAGS:= -lrt

.PHONY:=lib all clean

all: bin

bin:shmcreate shmunlink shmio

shmcreate:shmcreate.o common.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmunlink:shmunlink.o common.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmio:shmio.o common.o
	$(CXX) $^ $(LDFLAGS) -o $@

shmcreate.o:shmcreate.cpp shmdef.h
shmunlink.o:shmunlink.cpp shmdef.h
shmio.o:shmio.cpp shmdef.h

common.o:common.cpp common.h

clean:
	-rm *.o shmcreate shmunlink shmio
