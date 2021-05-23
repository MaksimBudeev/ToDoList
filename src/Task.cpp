#include "Task.h"

Task::Task(std::string newDate, std::string newText, int newPriority)
{
    date = newDate;
    text = newText;
    priority = newPriority;
}

Task::Task()
{
    date = "";
    text = "";
    priority = 0;
}

bool Task::operator==(const Task& b)
{
    return this->date == b.date && this->text == b.text && this->priority == b.priority;
}

bool Task::operator!=(const Task& b)
{
    return !(this == &b);
}

void setTaskForDate(std::vector<Task>& taskVector, std::string newDate, int newPriority, std::string newText)
{
    Task task(newDate, newText, newPriority);
    taskVector.push_back(task);
}

void getTaskForDate(std::vector<Task> taskVector, std::string date)
{
    std::vector<Task> helpVector;
    for (int i = 0; i < taskVector.size(); i++) {
        if (taskVector[i].getDate() == date) {
            helpVector.push_back(taskVector[i]);
        }
    }
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < helpVector.size(); j++) {
            if (helpVector[j].getPriority() == i) {
                std::cout << helpVector[j].getDate() << " " << helpVector[j].getPriority() << " " << helpVector[j].getText()
                          << std::endl;
            }
        }
    }
    helpVector.clear();
}

void deleteTask(std::vector<Task>& vector, std::string date, int priority, std::string text)
{
    for (int i = 0; i < vector.size(); i++) {
        if ((vector[i].getDate() == date) && (vector[i].getText() == text) && (vector[i].getPriority() == priority)) {
            vector.erase(vector.begin() + i);
            break;
        }
    }
}

void Task::setDate(std::string newDate)
{
    date = newDate;
}
void Task::setText(std::string newText)
{
    text = newText;
}
void Task::setPriority(int newPriority)
{
    priority = newPriority;
}

std::string Task::getDate() const
{
    return date;
}
std::string Task::getText() const
{
    return text;
}
int Task::getPriority() const
{
    return priority;
}

int findIndex(std::vector<Task>& taskVector, std::string date, int priority, std::string text)
{
    for (int i = 0; i < taskVector.size(); i++) {
        if ((taskVector[i].getDate() == date) && (taskVector[i].getText() == text) && (taskVector[i].getPriority() == priority)) {
            return i;
        }
    }
    return 1;
}

void changeTaskDate(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newDate)
{
    int number = findIndex(taskVector, date, priority, text);
    taskVector[number].setDate(newDate);
}

void changeTaskText(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newText)
{
    int number = findIndex(taskVector, date, priority, text);
    taskVector[number].setText(newText);
}

void changeTaskPriority(std::vector<Task>& taskVector, std::string date, int priority, std::string text, int newPriority)
{
    int number = findIndex(taskVector, date, priority, text);
    taskVector[number].setPriority(newPriority);
}

