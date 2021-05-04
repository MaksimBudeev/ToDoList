#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node {
private:
    string date;
    string text;
    int priority; //Приоритет задачи от 1 до 5
public:
    // Конструктор:
    Node(string date, string text, int priority);
    // Установить дату:
    void SetDate(string new_date);
    // Установить текст:
    void SetText(string new_text);
    // Установить приоритет:
    void SetPriority(int new_priority);
    // Вернуть значение даты:
    string GetDate();
    // Вернуть значение текста:
    string GetText();
    // Вернуть значение приоритета:
    int GetPriority();
};

void DeleteTask(vector<Node>& vector, string date, string text, int priority);
// добавление заметки:
void SetTaskForDate(vector<Node>& node_vector, string new_date, string new_text, int new_priority);
// вывод заметок на данную дату в консоль(временно):
void GetTaskForDate(vector<Node> node_vector, string date);
// изменение даты:
void ChangeTaskDate(vector<Node>& node_vector, string date, string text, int priority, string new_date);
// изменение текста заметки:
void ChangeTaskText(vector<Node>& node_vector, string date, string text, int priority, string new_text);
// изменение приоритета заметки:
void ChangeTaskPriority(vector<Node>& node_vector, string date, string text, int priority, int new_priority);
