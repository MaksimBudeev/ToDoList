#pragma once
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "Task.h"

using namespace std;

void writeInVector(vector<Task>& taskVector);
void setTaskInFile(vector<Task>& taskVector, string date, int priority, string text);
void changePriorityInFile(vector<Task>& taskVector, string date, int priority, string text, int newPriority);
void changeStringInFile(vector<Task>& taskVector, string date_p, int priority_p, string text_p, string newString, int typeString);
void changeDateInFile(vector<Task>& taskVector, string date, int priority, string text, string newDate);
void changeTextInFile(vector<Task>& taskVector, string date, int priority, string text, string newText);
void deleteTaskInFile(vector<Task>& taskVector, string date, int priority, string text);

