CC=gcc
CXX=g++
MAKE=make
TEMP:=gen-cpp

CFLAGS=-rdynamic -std=c++11 -g -Wall -I$(TEMP)
CXXFLAGS=-rdynamic -std=c++11 -g -Wall -I$(TEMP)

LDFLAGS=-rdynamic -lthriftnb -lthrift -levent -lpthread -lrt -lstdc++

RM=-rm -rf

SRCS+=$(filter-out %.skeleton.cpp,$(wildcard src/*.cpp $(TEMP)/*.cpp))
OBJS=$(SRCS:%.cpp=%.o)
DEPENDS=$(SRCS:%.cpp=%.d)


all:rpc_server

rpc_server:$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJS):%.o:%.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

-include $(DEPENDS)
$(DEPENDS):%.d:%.cpp
	set -e; rm -f $@; \
	$(CXX) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[:]*,\1.o $@:,g' < $@.$$$$ > $@; \
	rm $@.$$$$

clean:
	$(RM) $(OBJS) $(DEPENDS) rpc_server

fake:
	@echo $(OBJS)
