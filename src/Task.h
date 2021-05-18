#pragma once
#include <iostream>
#include <string>
#include <vector>


class Task {
private:
    std::string date;
    std::string text;
    int priority; //Приоритет задачи от 1 до 5
public:
    // Конструктор:
    Task(std::string date, std::string text, int priority);
    Task();
    // Установить дату:
    void SetDate(std::string newDate);
    // Установить текст:
    void SetText(std::string newText);
    // Установить приоритет:
    void SetPriority(int newPriority);
    // Вернуть значение даты:
    std::string GetDate()const;
    // Вернуть значение текста:
    std::string GetText()const;
    // Вернуть значение приоритета:
    int GetPriority()const;
    bool operator == (const Task & b);
    bool operator != (const Task & b);
};

void DeleteTask(std::vector<Task>& vector, std::string date, int priority, std::string text);
// добавление заметки:
void SetTaskForDate(std::vector<Task>& taskVector, std::string newDate, int newPriority, std::string newText);
// вывод заметок на данную дату в консоль(временно):
void GetTaskForDate(std::vector<Task> taskVector, std::string date);
// изменение даты:
void ChangeTaskDate(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newDate);
// изменение текста заметки:
void ChangeTaskText(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newText);
// изменение приоритета заметки:
void ChangeTaskPriority(std::vector<Task>& taskVector, std::string date, int priority, std::string text, int newPriority);
