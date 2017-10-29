PROJ_HOME = ../../..
LIB_DIR = $(PROJ_HOME)/lib
CORE_SRC_DIR = $(PROJ_HOME)/src/core
CXX = g++
OPT_FLAGS = -O2
DEBUG_FLAGS = -Wall -g
STD_FLAGS = -std=c++11
COMMON_FLAGS = $(OPT_FLAGS) $(DEBUG_FLAGS) $(STD_FLAGS)

targets = main 

all: $(targets)

libparser.a:
	make --directory=$(CORE_SRC_DIR)

main: main.cpp libparser.a
	$(CXX) $(COMMON_FLAGS) -o $@ $< -I$(CORE_SRC_DIR) -L$(LIB_DIR) -lparser

clean:
	rm -rf $(targets)
	make clean --directory=$(CORE_SRC_DIR)

