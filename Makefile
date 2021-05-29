CFLAGS = -Wall -Werror

SRC_PATH = src
TEST_PATH = test
LIB_TEST_DIR = thirdparty


SRC_EXT = cpp
.PHONY: all $(TEST_PATH)
all: $(TEST_PATH)
	
test:
	g++ -o $(TEST_PATH)/worked $(TEST_PATH)/*.cpp $(SRC_PATH)/Task.cpp $(SRC_PATH)/DataInput.cpp -I $(LIB_TEST_DIR) -I $(TEST_PATH) -I $(SRC_PATH)
