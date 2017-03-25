COMMON_DIR:=../../common

INCDIR:=$(COMMON_DIR)

CC:=clang++
CXX:=clang++
CXXFLAGS:=-g -Wall -I $(subst :, -I,$(INCDIR))
VPATH:=$(COMMON_DIR)
LDFLAGS:=-g -Wall -lrt

.PHONY:all clean

all:mqcreate mqunlink mqsend mqgetattr \
	mqrecv mqrecv1 mqrecv2 mqrecv3 mqrecv4

mqcreate:mqcreate.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqunlink:mqunlink.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqsend:mqsend.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqrecv:mqrecv.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqgetattr:mqgetattr.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqrecv1:mqrecv1.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqrecv2:mqrecv2.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqrecv3:mqrecv3.o common.o
	$(CC) $^ $(LDFLAGS) -o $@
mqrecv4:mqrecv4.o common.o
	$(CC) $^ $(LDFLAGS) -o $@

mqcreate.o:mqcreate.cpp mqdef.h
mqunlink.o:mqunlink.cpp mqdef.h
mqsend.o:mqsend.cpp mqdef.h
mqrecv.o:mqrecv.cpp mqdef.h
mqrecv1.o:mqrecv1.cpp mqdef.h
mqrecv2.o:mqrecv2.cpp mqdef.h
mqrecv3.o:mqrecv3.cpp mqdef.h
mqrecv4.o:mqrecv4.cpp mqdef.h
mqgetattr.o:mqgetattr.cpp mqdef.h

common.o:common.cpp common.h

clean:
	-rm *.o mqcreate mqunlink mqsend mqrecv mqrecv1 mqrecv2 mqrecv3 mqrecv4 mqgetattr
