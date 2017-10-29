PROJ_HOME = ../..
LIB_DIR = $(PROJ_HOME)/lib
CXX = g++
OPT_FLAGS = -O2
DEBUG_FLAGS = -Wall -g
STD_FLAGS = -std=c++11
COMMON_FLAGS = $(OPT_FLAGS) $(DEBUG_FLAGS) $(STD_FLAGS)

all: libparser.a

libparser.a: parser.o
	ar rvs $@ $^
	if [ ! -d $(LIB_DIR) ]; then mkdir -p $(LIB_DIR); fi
	cp $@ $(LIB_DIR)/$@

parser.o: parser.cpp
	$(CXX) $(COMMON_FLAGS) -c -o $@ $< -I.

clean:
	rm -rf *.o *.a $(LIB_DIR)/*.a
