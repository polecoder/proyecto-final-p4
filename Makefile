CXX = g++
CXXFLAGS = -Iinclude -std=c++11 -Wall -Wextra
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = programa

all: $(TARGET)

$(TARGET): $(OBJ)
    $(CXX) $(OBJ) -o $@

src/%.o: src/%.cpp
    $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
    rm -f src/*.o $(TARGET)