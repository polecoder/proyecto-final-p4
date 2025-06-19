# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -Iinclude -std=c++17
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN = main

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Regla principal
all: $(BIN)

# Compilación del ejecutable
$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $(BIN)

# Compilación de objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear directorio obj si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Limpiar archivos generados
clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean