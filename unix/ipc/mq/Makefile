SNAIL_ROOT:=../../snail
SNAIL_INC:=$(SNAIL_ROOT)/include
SNAIL_LIB:=$(SNAIL_ROOT)/lib/libsnail.lib

INCDIR:=$(SNAIL_INC)

CC:=clang++
CXX:=clang++
CXXFLAGS:=-g -Wall -I $(subst :, -I,$(INCDIR))
LDFLAGS:=-g -Wall -L $(SNAIL_ROOT)/lib -lsnail -lrt

.PHONY:all clean

all:$(SNAIL_LIB) mqcreate mqunlink mqsend mqgetattr \
	mqrecv mqrecv1 mqrecv2 mqrecv3 mqrecv4

mqcreate:mqcreate.o
	$(CC) $^ $(LDFLAGS) -o mqcreate 
mqunlink:mqunlink.o
	$(CC) $^ $(LDFLAGS) -o mqunlink 
mqsend:mqsend.o
	$(CC) $^ $(LDFLAGS) -o mqsend
mqrecv:mqrecv.o
	$(CC) $^ $(LDFLAGS) -o mqrecv
mqgetattr:mqgetattr.o
	$(CC) $^ $(LDFLAGS) -o mqgetattr
mqrecv1:mqrecv1.o
	$(CC) $^ $(LDFLAGS) -o mqrecv1
mqrecv2:mqrecv2.o
	$(CC) $^ $(LDFLAGS) -o mqrecv2
mqrecv3:mqrecv3.o
	$(CC) $^ $(LDFLAGS) -o mqrecv3
mqrecv4:mqrecv4.o
	$(CC) $^ $(LDFLAGS) -o mqrecv4

mqcreate.o:mqcreate.cpp mqdef.h
mqunlink.o:mqunlink.cpp mqdef.h
mqsend.o:mqsend.cpp mqdef.h
mqrecv.o:mqrecv.cpp mqdef.h
mqrecv1.o:mqrecv1.cpp mqdef.h
mqrecv2.o:mqrecv2.cpp mqdef.h
mqrecv3.o:mqrecv3.cpp mqdef.h
mqrecv4.o:mqrecv4.cpp mqdef.h
mqgetattr.o:mqgetattr.cpp mqdef.h

$(SNAIL_LIB):
	cd $(SNAIL_ROOT) && $(MAKE)

clean:
	-rm *.o mqcreate mqunlink mqsend mqrecv mqrecv1 mqrecv2 mqrecv3 mqrecv4 mqgetattr
