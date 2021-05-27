APP_TEST_NAME = test

CFLAGS = -Wall -Werror

SRC_PATH = ../src/Task.cpp
SRC_PATH2 = ../src
LIB_TEST_DIR = ../thirdparty


SRC_EXT = cpp

all: test
	
test: 
	g++ -o worked classTask_test.cpp main.cpp $(SRC_PATH) -I $(LIB_TEST_DIR) -I $(SRC_PATH2)
