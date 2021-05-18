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

bool Task::operator == (const Task &b){
	if(this->date == b.date && this->text == b.text && this->priority == b.priority){
		return true;
	}else{
		return false;
	}
}

bool Task::operator != (const Task &b){
	if(this->date == b.date && this->text == b.text && this->priority == b.priority){
		return false;
	}else{
		return true;
	}
}	

void SetTaskForDate(std::vector<Task>& taskVector, std::string newDate, int newPriority, std::string newText)
{
    Task task(newDate, newText, newPriority);
    taskVector.push_back(task);
}

void GetTaskForDate(std::vector<Task> taskVector, std::string date)
{
    std::vector<Task> helpVector;
    for (int i = 0; i < taskVector.size(); i++) {
        if (taskVector[i].GetDate() == date) {
            helpVector.push_back(taskVector[i]);
        }
    }
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < helpVector.size(); j++) {
            if (helpVector[j].GetPriority() == i) {
                std::cout << helpVector[j].GetDate() << " " << helpVector[j].GetPriority() << " " << helpVector[j].GetText() << std::endl;
            }
        }
    }
    helpVector.clear();
}

void DeleteTask(std::vector<Task>& vector, std::string date, int priority, std::string text)
{
    for (int i = 0; i < vector.size(); i++) {
        if ((vector[i].GetDate() == date) && (vector[i].GetText() == text) && (vector[i].GetPriority() == priority)) {
            vector.erase(vector.begin() + i);
            break;
        }
    }
}

void Task::SetDate(std::string newDate)
{
    date = newDate;
}
void Task::SetText(std::string newText)
{
    text = newText;
}
void Task::SetPriority(int newPriority)
{
    priority = newPriority;
}

std::string Task::GetDate()const
{
    return date;
}
std::string Task::GetText()const
{
    return text;
}
int Task::GetPriority()const
{
    return priority;
}

int FindIndex(std::vector<Task>& taskVector, std::string date, int priority, std::string text){
	for (int i = 0; i < taskVector.size(); i++) {
        if ((taskVector[i].GetDate() == date) && (taskVector[i].GetText() == text) && (taskVector[i].GetPriority() == priority)) {
            return i;
        }
    }
    return 1;
}

void ChangeTaskDate(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newDate)
{
	int number = FindIndex(taskVector,date,priority,text);
    taskVector[number].SetDate(newDate);
}

void ChangeTaskText(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newText)
{
    int number = FindIndex(taskVector,date,priority,text);
    taskVector[number].SetText(newText);
}

void ChangeTaskPriority(std::vector<Task>& taskVector, std::string date, int priority, std::string text, int newPriority)
{
    int number = FindIndex(taskVector,date,priority,text);
    taskVector[number].SetPriority(newPriority);
}

