#include "Node.h"

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
