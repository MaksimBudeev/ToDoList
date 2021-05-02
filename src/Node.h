#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
	string key; 
	string text;
	int priority;  //Приоритет задачи от 1 до 5
public:
	void SetKey(string new_key);
	void SetText(string new_text);
	void SetPriority(int new_priority);
	string GetKey();
	string GetText();
	int GetPriority();
};
