CC:=clang
CXX:=clang++

CFLAGS+=-g -Wall
CXXFLAGS+=-g -Wall

LDFLAGS:=-lcrypto

RM=-rm -rf

SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)
BINS=$(SRCS:%.c=%.out)
DEPENDS=$(SRCS:%.c=%.d)

all:$(BINS)

$(BINS):%.out:%.o
	$(CC) -o $@ $< $(LDFLAGS)

$(OBJS):%.o:%.c
	$(CC) -c $< -o $@ $(CFLAGS)

-include $(DEPENDS)

$(DEPENDS):%.d:%.c
	set -e; rm -f $@; \
	$(CC) -MM $(CFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[:]*,\1.o $@:,g' < $@.$$$$ > $@; \
	rm $@.$$$$

clean:
	$(RM) $(BINS) $(LIB) $(OBJS) $(DEPENDS)

# for debug
fake:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(BINS)
