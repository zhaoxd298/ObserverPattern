CXX = g++
CFLAGS = -Wall
LDFLAGS = 

target = res
srcs = main.cpp
objs = $(srcs:.cpp=.o)

.PHONY: all
all: $(target)

$(target): $(objs)
	$(CXX) $(LDFLAGS) -o $(target) $^

$(objs):%.o:%.cpp
	$(CXX) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(target) *.o

