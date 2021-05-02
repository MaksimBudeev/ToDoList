#include "Node.h"

Node::Node(string new_key, string new_text, int new_priority){
	key = new_key;
	text = new_text;
	priority = new_priority;
}

void Node::SetKey(string new_key){
	key = new_key;
}
void Node::SetText(string new_text){
	text = new_text;
}
void Node::SetPriority(int new_priority){
	priority = new_priority;
}

string Node::GetKey(){
	return key;
}
string Node::GetText(){
	return text;
}
int Node::GetPriority(){
	return priority;
}
