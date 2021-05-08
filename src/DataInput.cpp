#include "DataInput.h"
#include "Node.h"

string date;
string prior;
string text;
int priority;
int command;
int ch = 0; //чтение символов
int i = 0;  //счёт символов
int TypeString = -1;

void UpdateTask(vector<Node>& node_vector)
{
    ifstream Task("task.txt", ios::in);  //открыли для чтения  файл
    if (!Task.is_open()) {               // если файл не открыт
        cout << "Файл не был найден!\n"; // сообщить об этом
        return;
    }
    while ((ch = Task.get()) != EOF) { //пока файл не кончился
        if (char(ch) != '\n') {        //пока не конец строки
            if (i < 10) {              //первые 10 символов добавляются в дату
                date = date + char(ch);
                i++;
            } else {
                if (i < 13) {
                    if (char(ch) != ' ') {
                        prior = prior + char(ch);
                        priority = stoi(prior); //преобразование в инт
                    }
                    i++;
                } else {
                    text = text + char(ch); //оставшиеся символы в текст
                }
            }
        } else {
            SetTaskForDate(node_vector, date, priority, text);
            i = 0; //обнуляем счётчик символов для новой строки
            date.clear();
            prior.clear();
            text.clear();
        }
    }
    Task.close(); //Закрываем файл
}

void SetTaskInFile(vector<Node>& node_vector, string date, int priority, string text)
{
    fstream Task;
    Task.open("task.txt", ios::app); // окрываем файл для записи

    Task << date << " " << priority << " " << text << endl;
    SetTaskForDate(node_vector, date, priority, text);
    cout << "Заметка добавлена" << endl;
    date.clear();
    prior.clear();
    text.clear();
    Task.close();
}

void ChangeStringInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string new_string, int TypeString)
{
    fstream Temp;
    fstream Task;

    Task.open("task.txt", ios::in);  //открыли для чтения  файл
    Temp.open("temp.txt", ios::out); // окрываем файл для записи

    if (!Task.is_open()) {               // если файл не открыт
        cout << "Файл не был найден!\n"; // сообщить об этом
        return;
    }
    if (!Temp.is_open()) {               // если файл не открыт
        cout << "Файл не был найден!\n"; // сообщить об этом
        return;
    }

    while ((ch = Task.get()) != EOF) { //пока файл не кончился
        if (char(ch) != '\n') {        //пока не конец строки
            if (i < 10) {              //первые 10 символов добавляются в дату
                date = date + char(ch);
                i++;
            } else {
                if (i < 13) {
                    if (char(ch) != ' ') {
                        prior = prior + char(ch);
                        priority = stoi(prior); //преобразование в инт
                    }
                    i++;
                } else {
                    text = text + char(ch); //оставшиеся символы в текст
                }
            }
        } else {
            if ((date == date_p) && (priority == priority_p) && (text == text_p)) {
                if (TypeString == 0) {
                    ChangeTaskDate(node_vector, date_p, priority_p, text_p, new_string);
                    Temp << new_string << " " << priority_p << " " << text_p << endl;
                }
                if (TypeString == 1) {
                    ChangeTaskText(node_vector, date_p, priority_p, text_p, new_string);
                    Temp << date_p << " " << priority_p << " " << new_string << endl;
                }
                if (TypeString == 2) {
                    int newPriority = stoi(new_string); //преобразование в инт
                    ChangeTaskPriority(node_vector, date_p, priority_p, text_p, newPriority);
                    Temp << date_p << " " << newPriority << " " << text_p << endl;
                }
                if (TypeString == 3) {
                    DeleteTask(node_vector, date_p, priority_p, text_p);
                }
            } else {
                Temp << date << " " << priority << " " << text << endl;
            }
            i = 0; //обнуляем счётчик символов для новой строки
            date.clear();
            prior.clear();
            text.clear();
        }
    }
    Task.close(); //Закрываем файл
    Temp.close(); //Закрываем файл

    Temp.open("temp.txt", ios::in);  //открыли для чтения  файл
    Task.open("task.txt", ios::out); // окрываем файл для записи

    while ((ch = Temp.get()) != EOF) { //пока файл не кончился
        if (char(ch) != '\n') {        //пока не конец строки
            if (i < 10) {              //первые 10 символов добавляются в дату
                date = date + char(ch);
                i++;
            } else {
                if (i < 13) {
                    if (char(ch) != ' ') {
                        prior = prior + char(ch);
                        priority = stoi(prior); //преобразование в инт
                    }
                    i++;
                } else {
                    text = text + char(ch); //оставшиеся символы в текст
                }
            }
        } else {
            Task << date << " " << priority << " " << text << endl;
            i = 0; //обнуляем счётчик символов для новой строки
            date.clear();
            prior.clear();
            text.clear();
        }
    }

    Task.close(); //Закрываем файл
    Temp.close(); //Закрываем файл
}

void ChangeDateInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string newDate)
{
    TypeString = 0;
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, newDate, TypeString);
}
void ChangeTextInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, string newText)
{
    TypeString = 1;
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, newText, TypeString);
}
void ChangePriorityInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p, int newPriority)
{
    TypeString = 2;
    string prior = to_string(newPriority); //преобразование в стринг
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, prior, TypeString);
}
void DeleteTaskInFile(vector<Node>& node_vector, string date_p, int priority_p, string text_p)
{
    TypeString = 3;
    ChangeStringInFile(node_vector, date_p, priority_p, text_p, "", TypeString);
}
