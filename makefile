CXX = g++
OPT_FLAGS = -O2
DEBUG_FLAGS = -Wall -g
STD_FLAGS = -std=c++11
COMMON_FLAGS = $(OPT_FLAGS) $(DEBUG_FLAGS) $(STD_FLAGS)

all: base test

base: parser libparser.a

parser: parser.cpp
	$(CXX) $(COMMON_FLAGS) -c $<

libparser.a: parser.o
	ar rvs $@ $^

test: test.cpp
	$(CXX) $(COMMON_FLAGS) -o $@ $< -I. -L. -lparser

clean:
	rm -rf *.o *.a test
