.PHONY: all clean

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = ToDo

OBJ = $(OBJ_DIR)/main.o $(OBJ_DIR)/Node.o $(OBJ_DIR)/DataInput.o

all: $(TARGET)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	g++ -c -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.cpp
$(OBJ_DIR)/Node.o: $(SRC_DIR)/Node.cpp
	g++ -c -o $(OBJ_DIR)/Node.o $(SRC_DIR)/Node.cpp
$(OBJ_DIR)/DataInput.o: $(SRC_DIR)/DataInput.cpp
	g++ -c -o $(OBJ_DIR)/DataInput.o $(SRC_DIR)/DataInput.cpp	
	
$(TARGET): $(OBJ)
	g++ -Wall -g -o $(BIN_DIR)/$(TARGET) $(OBJ)
	
clean:
	rm -rf $(BIN_DIR)/$(TARGET)
	rm -rf $(OBJ_DIR)/*.o 
