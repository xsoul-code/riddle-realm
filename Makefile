# Compiler
CXX = g++
# Compiler flags 
CXXFLAGS = -Wall -Wextra -std=c++20 -Iinclude
# Target executable
TARGET = riddlerealm
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

