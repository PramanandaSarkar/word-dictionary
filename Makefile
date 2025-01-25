# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directories
SRC_DIR = src
BIN_DIR = bin
OBJ_DIR = obj

# Output binary
TARGET = $(BIN_DIR)/application

# Source files and object files
SRCS = main.c $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))

# Default rule
all: setup $(TARGET)

# Create necessary directories
setup:
	mkdir -p $(BIN_DIR) $(OBJ_DIR)

# Compile the application
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Compile source files into object files
$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)

# Run the application
run: $(TARGET)
	./$(TARGET)

.PHONY: all setup clean run
