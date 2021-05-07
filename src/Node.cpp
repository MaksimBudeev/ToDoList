#include "Node.h"

Node::Node(string newDate, string newText, int newPriority)
{
    date = newDate;
    text = newText;
    priority = newPriority;
}

Node::Node()
{
	date = "";
	text = "";
	priority = 0;
}

bool Node::operator == (const Node &b){
	if(this->date == b.date && this->text == b.text && this->priority == b.priority){
		return true;
	}else{
		return false;
	}
}

bool Node::operator != (const Node &b){
	if(this->date == b.date && this->text == b.text && this->priority == b.priority){
		return false;
	}else{
		return true;
	}
}	

void SetTaskForDate(vector<Node>& nodeVector, string newDate, int newPriority, string newText)
{
    Node node(newDate, newText, newPriority);
    nodeVector.push_back(node);
}

void GetTaskForDate(vector<Node> nodeVector, string date)
{
    vector<Node> helpVector;
    for (int i = 0; i < nodeVector.size(); i++) {
        if (nodeVector[i].GetDate() == date) {
            helpVector.push_back(nodeVector[i]);
        }
    }
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < helpVector.size(); j++) {
            if (helpVector[j].GetPriority() == i) {
                cout << helpVector[j].GetDate() << " " << helpVector[j].GetPriority() << " " << helpVector[j].GetText() << endl;
            }
        }
    }
    helpVector.clear();
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

void Node::SetDate(string newDate)
{
    date = newDate;
}
void Node::SetText(string newText)
{
    text = newText;
}
void Node::SetPriority(int newPriority)
{
    priority = newPriority;
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

void ChangeTaskDate(vector<Node>& nodeVector, string date, int priority, string text, string newDate)
{
    for (int i = 0; i < nodeVector.size(); i++) {
        if ((nodeVector[i].GetDate() == date) && (nodeVector[i].GetText() == text) && (nodeVector[i].GetPriority() == priority)) {
            nodeVector[i].SetDate(newDate);
            break;
        }
    }
}

void ChangeTaskText(vector<Node>& nodeVector, string date, int priority, string text, string newText)
{
    for (int i = 0; i < nodeVector.size(); i++) {
        if ((nodeVector[i].GetDate() == date) && (nodeVector[i].GetText() == text) && (nodeVector[i].GetPriority() == priority)) {
            nodeVector[i].SetText(newText);
            break;
        }
    }
}

void ChangeTaskPriority(vector<Node>& nodeVector, string date, int priority, string text, int newPriority)
{
    for (int i = 0; i < nodeVector.size(); i++) {
        if ((nodeVector[i].GetDate() == date) && (nodeVector[i].GetText() == text) && (nodeVector[i].GetPriority() == priority)) {
            nodeVector[i].SetPriority(newPriority);
            break;
        }
    }
}

