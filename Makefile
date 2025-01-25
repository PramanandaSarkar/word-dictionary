CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -std=c11 -O2
CXXFLAGS = -Wall -Wextra -std=c++11 -O2

SRC_C = src/customHashMap/HashMap.c src/customHashMap/Tree.c src/utils/helper.c src/customHashMap/Application.c src/main.c
SRC_CPP = src/libhashmap/Application.cpp
OBJ_C = $(SRC_C:src/%.c=obj/%.o)
OBJ_CPP = $(SRC_CPP:src/%.cpp=obj/%.o)
OBJ = $(OBJ_C) $(OBJ_CPP)
BIN = bin/hashmap_tree_comparison

all: $(BIN)

$(BIN): $(OBJ)
	mkdir -p bin
	$(CXX) $(OBJ) -o $@

obj/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(BIN)

clean:
	rm -rf obj bin logs/*.log
