#include "DataInput.h"
#include "Task.h"

void setTaskInFile(vector<Task>& taskVector, string date, int priority, string text)
{
    fstream storage("storage.txt", ios::app);
        storage << date << " " << priority << " " << text << endl;
    setTaskForDate(taskVector, date, priority, text);
    storage.close();
}

void changeStringInFile(vector<Task>& taskVector, string date_p, int priority_p, string text_p, string newString, int typeString)
{
    int readChar = 0;
    int charCount = 0;
    string date;
    string prior;
    string text;
    int priority;

    fstream storage("storage.txt", ios::in);
    fstream cache("cache.txt", ios::out);          

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
                    cache << newString << " " << priority_p << " " << text_p << endl;
                }
                if (typeString == 2) {
                    changeTaskText(taskVector, date_p, priority_p, text_p, newString);
                    cache << date_p << " " << priority_p << " " << newString << endl;
                }
                if (typeString == 3) {
                    int newPriority = stoi(newString);
                    changeTaskPriority(taskVector, date_p, priority_p, text_p, newPriority);
                    cache << date_p << " " << newPriority << " " << text_p << endl;
                }
                if (typeString == 4) {
                    deleteTask(taskVector, date_p, priority_p, text_p);
                }

            } else {
               cache << date << " " << priority << " " << text << endl;
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

    cache.open("cache.txt", ios::in);
    storage.open("storage.txt", ios::out);

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
            storage << date << " " << priority << " " << text << endl;
            charCount = 0;
            date.clear();
            prior.clear();
            text.clear();
        }
    }

    storage.close();
    cache.close(); 
}

void writeInVector(vector<Task>& taskVector)
{
    int typeString = 0;
    changeStringInFile(taskVector, "", 0, "", "", typeString);
}

void changeDateInFile(vector<Task>& taskVector, string date, int priority, string text, string newDate)
{
    int typeString = 1;
    changeStringInFile(taskVector, date, priority, text, newDate, typeString);
}
void changeTextInFile(vector<Task>& taskVector, string date, int priority, string text, string newText)
{
    int typeString = 2;
    changeStringInFile(taskVector, date, priority, text, newText, typeString);
}
void changePriorityInFile(vector<Task>& taskVector, string date, int priority, string text, int newPriority)
{
    int typeString = 3;
    string prior = to_string(newPriority);
    changeStringInFile(taskVector, date, priority, text, prior, typeString);
}
void deleteTaskInFile(vector<Task>& taskVector, string date, int priority, string text)
{
    int typeString = 4;
    changeStringInFile(taskVector, date, priority, text, "", typeString);
}
