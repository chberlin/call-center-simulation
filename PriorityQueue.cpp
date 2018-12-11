
#include "PriorityQueue.h"
#include <iostream>
PriorityQueue::PriorityQueue(){
	head = nullptr;
	size = 0;
}
PriorityQueue::~PriorityQueue(){
	Node* current = head;
	while(current != nullptr){
		Node* n = current -> next;
		delete current;
		current = n;
	}
	head = nullptr;
}
bool PriorityQueue::isEmpty() const{
	assert(size >=0);
	if(size == 0 && head == nullptr){
		return true;
	}	
	else{
		return false;
	}
}
 
int PriorityQueue::getLength() const{
	return size;
}

void PriorityQueue::Push(ItemType c){
	Node* newCall = new Node();
	newCall -> data = c;
	Node* front = head;

	if(head == nullptr){
		newCall -> next = nullptr;
		head = newCall;
	}
	else if(newCall->data < head-> data){
		head = newCall;
		newCall -> next = front;
	}
	else{
		while(front -> next != nullptr &&
			front -> next -> data < newCall -> data){
				front = front -> next;
			
		}
		newCall -> next = front -> next;
		front -> next = newCall;
	}
	size++;

}
void PriorityQueue::Pop(){
	assert(!isEmpty());
	if(size == 1 && head->next == nullptr){
		Node* temp = head;
		delete temp;
		head = nullptr;
	}
	else{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	size--;
}

ItemType PriorityQueue::Peek()const{
	assert(!isEmpty());
	ItemType fgdg = head -> data;
	return head -> data;
}