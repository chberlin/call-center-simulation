#ifndef priorityqueue_
#define priorityqueue_

#include <cassert>
#include "Call.h"
using namespace std;



typedef Call ItemType;

class PriorityQueue{              
public:
   PriorityQueue();

   ~PriorityQueue();
   // interface methods
   bool isEmpty() const;
   //Precondition: Cannot have less than 0 elements on stack
   //input: None
   //output: Returns true if the stack is empty
   //output: Returns false if the stack is not empty
   //side effect
   int getLength() const;
   //input: None
   //output:Returns the number of items in the queue
   //side effect: None
   void Push(ItemType c);
   //input: ItemType element
   //output: None
   //side effect: Places element in sorted area
   void Pop();
   //Precondition: Priroity Queue cannot be empty;
   //input: None
   //side effect: Element is removed from front oof queue
   ItemType Peek() const;
   //input: None
   //output: Returns element ontop of stack
   //side effect: None

private:
	class Node {
	public:
      ItemType data;
		Node* next;
	};
	Node* head;
	int size;
};

#endif