APP_TEST_NAME = test

CFLAGS = -Wall -Werror

SRC_PATH = ../src/
LIB_TEST_DIR = ../thirdparty


SRC_EXT = cpp

all: test
	
test: 
	g++ -o worked *.cpp $(SRC_PATH)Task.cpp $(SRC_PATH)DataInput.cpp -I $(LIB_TEST_DIR) -I $(SRC_PATH)
