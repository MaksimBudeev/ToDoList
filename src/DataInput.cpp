#include "DataInput.h"
#include "Task.h"


void setTaskInFile(std::vector<Task>& taskVector, std::string date, int priority, std::string text)
{
    std::fstream storage("storage.txt", std::ios::app);
        storage << date << " " << priority << " " << text << std::endl;
    setTaskForDate(taskVector, date, priority, text);
    storage.close();
}

void changeStringInFile(std::vector<Task>& taskVector, std::string date_p, int priority_p, std::string text_p, std::string newString, int typeString)
{
    int readChar = 0;
    int charCount = 0;
    std::string date;
    std::string prior;
    std::string text;
    int priority;

    std::fstream storage("storage.txt", std::ios::in);
    std::fstream cache("cache.txt", std::ios::out);          

    while ((readChar = storage.get()) != EOF) {
        if (char(readChar) != '\n') {
            if (charCount < 10) {
                date = date + char(readChar);
                charCount++;
            } else {
                if (charCount < 13) {
                    if (char(readChar) != ' ') {
                        prior = prior + char(readChar);
                        priority = stoi(prior);
                    }
                    charCount++;
                } else {
                    text = text + char(readChar);
                }
            }
        } else {
            if ((date == date_p) && (priority == priority_p) && (text == text_p)) {
                if (typeString == 1) {
                    changeTaskDate(taskVector, date_p, priority_p, text_p, newString);
                    cache << newString << " " << priority_p << " " << text_p << std::endl;
                }
                if (typeString == 2) {
                    changeTaskText(taskVector, date_p, priority_p, text_p, newString);
                    cache << date_p << " " << priority_p << " " << newString << std::endl;
                }
                if (typeString == 3) {
                    int newPriority = stoi(newString);
                    changeTaskPriority(taskVector, date_p, priority_p, text_p, newPriority);
                    cache << date_p << " " << newPriority << " " << text_p << std::endl;
                }
                if (typeString == 4) {
                    deleteTask(taskVector, date_p, priority_p, text_p);
                }

            } else {
               cache << date << " " << priority << " " << text << std::endl;
                if (typeString == 0) {
                    setTaskForDate(taskVector, date, priority, text);
                }
            }
            charCount = 0;
            date.clear();
            prior.clear();
            text.clear();
        }
    }

    storage.close();
    cache.close();

    cache.open("cache.txt", std::ios::in);
    storage.open("storage.txt", std::ios::out);

    while ((readChar = cache.get()) != EOF) {
        if (char(readChar) != '\n') {
            if (charCount < 10) {
                date = date + char(readChar);
                charCount++;
            } else {
                if (charCount < 13) {
                    if (char(readChar) != ' ') {
                        prior = prior + char(readChar);
                        priority = stoi(prior);
                    }
                    charCount++;
                } else {
                    text = text + char(readChar);
                }
            }
        } else {
            storage << date << " " << priority << " " << text << std::endl;
            charCount = 0;
            date.clear();
            prior.clear();
            text.clear();
        }
    }

    storage.close();
    cache.close(); 
}

void writeInVector(std::vector<Task>& taskVector)
{
    int typeString = 0;
    changeStringInFile(taskVector, "", 0, "", "", typeString);
}

void changeDateInFile(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newDate)
{
    int typeString = 1;
    changeStringInFile(taskVector, date, priority, text, newDate, typeString);
}
void changeTextInFile(std::vector<Task>& taskVector, std::string date, int priority, std::string text, std::string newText)
{
    int typeString = 2;
    changeStringInFile(taskVector, date, priority, text, newText, typeString);
}
void changePriorityInFile(std::vector<Task>& taskVector, std::string date, int priority, std::string text, int newPriority)
{
    int typeString = 3;
    std::string prior = std::to_string(newPriority);
    changeStringInFile(taskVector, date, priority, text, prior, typeString);
}
void deleteTaskInFile(std::vector<Task>& taskVector, std::string date, int priority, std::string text)
{
    int typeString = 4;
    changeStringInFile(taskVector, date, priority, text, "", typeString);
}
