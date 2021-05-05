#include "Node.h"

Node::Node(string new_date, string new_text, int new_priority)
{
    date = new_date;
    text = new_text;
    priority = new_priority;
}

void SetTaskForDate(vector<Node>& node_vector, string new_date, int new_priority, string new_text)
{
    Node node(new_date, new_text, new_priority);
    node_vector.push_back(node);
}

void GetTaskForDate(vector<Node> node_vector, string date)
{
    vector<Node> help_vector;
    for (int i = 0; i < node_vector.size(); i++) {
        if (node_vector[i].GetDate() == date) {
            help_vector.push_back(node_vector[i]);
        }
    }
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < help_vector.size(); j++) {
            if (help_vector[j].GetPriority() == i) {
                cout << help_vector[j].GetDate() << " " << help_vector[j].GetPriority() << " " << help_vector[j].GetText() << endl;
            }
        }
    }
    help_vector.clear();
}

void DeleteTask(vector<Node>& vector, string date, int priority, string text)
{
    for (int i = 0; i < vector.size(); i++) {
        if ((vector[i].GetDate() == date) && (vector[i].GetText() == text) && (vector[i].GetPriority() == priority)) {
            vector.erase(vector.begin() + i);
            break;
        }
    }
}

void Node::SetDate(string new_date)
{
    date = new_date;
}
void Node::SetText(string new_text)
{
    text = new_text;
}
void Node::SetPriority(int new_priority)
{
    priority = new_priority;
}

string Node::GetDate()
{
    return date;
}
string Node::GetText()
{
    return text;
}
int Node::GetPriority()
{
    return priority;
}

void ChangeTaskDate(vector<Node>& node_vector, string date, int priority, string text, string new_date)
{
    for (int i = 0; i < node_vector.size(); i++) {
        if ((node_vector[i].GetDate() == date) && (node_vector[i].GetText() == text) && (node_vector[i].GetPriority() == priority)) {
            node_vector[i].SetDate(new_date);
            break;
        }
    }
}

void ChangeTaskText(vector<Node>& node_vector, string date, int priority, string text, string new_text)
{
    for (int i = 0; i < node_vector.size(); i++) {
        if ((node_vector[i].GetDate() == date) && (node_vector[i].GetText() == text) && (node_vector[i].GetPriority() == priority)) {
            node_vector[i].SetText(new_text);
            break;
        }
    }
}

void ChangeTaskPriority(vector<Node>& node_vector, string date, int priority, string text, int new_priority)
{
    for (int i = 0; i < node_vector.size(); i++) {
        if ((node_vector[i].GetDate() == date) && (node_vector[i].GetText() == text) && (node_vector[i].GetPriority() == priority)) {
            node_vector[i].SetPriority(new_priority);
            break;
        }
    }
}

