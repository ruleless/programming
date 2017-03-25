CC:= clang
CXX:= clang++
CPPFLAGS:= -O0 -g
LDFLAGS:=

all: test.out

test.out: test.o
	$(CXX) -o $@ $^ $(LDFLAGS)
test.o: test.cpp

clean:
	-rm *.out *.o
