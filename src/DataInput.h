#pragma once
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "Task.h"

void writeInVector(std::vector<Task>& taskVector);
void setTaskInFile(std::vector<Task>& taskVector, std::string date, int priority, std::string text);

void changePriorityInFile(std::vector<Task>& taskVector, std::string date, int priority, 
std::string text, int newPriority);

void changeStringInFile(std::vector<Task>& taskVector, std::string date_p, int priority_p, 
std::string text_p, std::string newString, int typeString);

void changeDateInFile(std::vector<Task>& taskVector, std::string date, int priority, 
std::string text, std::string newDate);

void changeTextInFile(std::vector<Task>& taskVector, std::string date, int priority, 
std::string text, std::string newText);

void deleteTaskInFile(std::vector<Task>& taskVector, std::string date, int priority, 
std::string text);

