SNAIL_DIR:=../../snail/lib
SNAIL_LIB:=$(SNAIL_DIR)/libsnail.lib

CC:=clang++
CXX:=clang++
CXXFLAGS:=-g -Wall -I $(SNAIL_DIR)
LDFLAGS:=-L $(SNAIL_DIR) -lsnail -lrt

all:lib exe

lib:
	cd $(SNAIL_DIR) && $(MAKE)

exe:shmget shmrm shmwrite shmread

shmget:shmget.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmrm:shmrm.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmwrite:shmwrite.o
	$(CXX) $^ $(LDFLAGS) -o $@
shmread:shmread.o
	$(CXX) $^ $(LDFLAGS) -o $@

shmget.o:shmget.cpp shmdef.h
shmrm.o:shmrm.cpp shmdef.h
shmwrite.o:shmwrite.cpp shmdef.h
shmread.o:shmread.cpp shmdef.h

clean:
	-rm *.o shmget shmrm shmwrite shmread
