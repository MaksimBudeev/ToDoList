#pragma once
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <sstream>
#include "Task.h"

enum class Operation{
	Read,
	Edit,
	Delete,
	Add
};

void changeStringInFile(std::vector<Task>& taskVector, size_t index, Operation type);
