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
    Node();
    // Установить дату:
    void SetDate(string newDate);
    // Установить текст:
    void SetText(string newText);
    // Установить приоритет:
    void SetPriority(int newPriority);
    // Вернуть значение даты:
    string GetDate();
    // Вернуть значение текста:
    string GetText();
    // Вернуть значение приоритета:
    int GetPriority();
};

void DeleteTask(vector<Node>& vector, string date, int priority, string text);
// добавление заметки:
void SetTaskForDate(vector<Node>& nodeVector, string newDate, int newPriority, string newText);
// вывод заметок на данную дату в консоль(временно):
void GetTaskForDate(vector<Node> nodeVector, string date);
// изменение даты:
void ChangeTaskDate(vector<Node>& nodeVector, string date, int priority, string text, string newDate);
// изменение текста заметки:
void ChangeTaskText(vector<Node>& nodeVector, string date, int priority, string text, string newText);
// изменение приоритета заметки:
void ChangeTaskPriority(vector<Node>& nodeVector, string date, int priority, string text, int newPriority);
