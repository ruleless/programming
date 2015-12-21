SNAIL_ROOT:=../../../snail
SNAIL_INC:=$(SNAIL_ROOT)/include
SNAIL_LIB:=$(SNAIL_ROOT)/lib

LIB_DIR:=$(SNAIL_ROOT)/lib

CXXFLAGS:=-g -Wall -I $(subst :, -I,$(SNAIL_INC))
LDFLAGS:=-L $(LIB_DIR) -lsnail -lrt

.PHONY:=lib all clean

all:lib bin

lib:
	cd $(SNAIL_ROOT) && $(MAKE)
bin:shmcreate shmunlink shmio

shmcreate:shmcreate.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmunlink:shmunlink.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmio:shmio.o
	$(CXX) $^ $(LDFLAGS) -o $@

shmcreate.o:shmcreate.cpp shmdef.h
shmunlink.o:shmunlink.cpp shmdef.h
shmio.o:shmio.cpp shmdef.h

clean:
	-rm *.o shmcreate shmunlink shmio
