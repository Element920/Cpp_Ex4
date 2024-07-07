# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
# SFML libraries
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR := .
BUILD_DIR := build
BIN_DIR := bin

# Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
EXEC := $(BIN_DIR)/demo

# Targets
.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(SFML_LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

-include $(DEPS)
