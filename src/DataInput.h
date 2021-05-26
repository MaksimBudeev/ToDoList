#pragma once
#include "Task.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

enum Operation { Read, Edit, Delete, Add };

void changeStringInFile(std::vector<Task>& taskVector, size_t index, Operation type);
