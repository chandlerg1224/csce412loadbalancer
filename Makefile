# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -Wextra -g

# Directories
SRC_DIR := .
OBJ_DIR := obj
BIN_DIR := bin

# Source files
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Target executable
TARGET := $(BIN_DIR)/main.exe

# Default target
all: create_dirs $(TARGET)

# Create necessary directories
create_dirs:
	@if not exist $(OBJ_DIR) (mkdir $(OBJ_DIR))
	@if not exist $(BIN_DIR) (mkdir $(BIN_DIR))

# Link object files to create the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean up build files
clean:
	@if exist $(OBJ_DIR) (rmdir /s /q $(OBJ_DIR))
	@if exist $(BIN_DIR) (rmdir /s /q $(BIN_DIR))

# Phony targets
.PHONY: all clean create_dirs
