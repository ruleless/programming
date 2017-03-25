CXX:=clang++
CXXFLAGS:=-g -Wall

targets:=semcreate semrm semgetvals semsetvals semop

all:$(targets)

semcreate:semcreate.o semdef.o
	$(CXX) -o $@ $^
semrm:semrm.o semdef.o
	$(CXX) -o $@ $^
semgetvals:semgetvals.o semdef.o
	$(CXX) -o $@ $^
semsetvals:semsetvals.o semdef.o
	$(CXX) -o $@ $^
semop:semop.o semdef.o
	$(CXX) -o $@ $^

semcreate.o:semcreate.cpp semdef.h
semrm.o:semrm.cpp semdef.h
semgetvals.o:semgetvals.cpp semdef.h
semsetvals.o:semsetvals.cpp semdef.h
semop.o:semop.cpp semdef.h
semdef.o:semdef.h semdef.cpp

clean:
	rm *.o $(targets)
