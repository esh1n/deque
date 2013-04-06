#pragma once
#include <iostream>

// Each node in a doubly linked list
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class deque
{
	public:
		deque();
		~deque(void);
		void InsertFront(int element);
        int RemoveFront();
        void InsertBack(int element);
        int RemoveBack();
        int Front();
        int Back();
        int Size();
        bool isEmpty();

    private:
		 Node *front;
		 Node* back;
	     int count;
    
};
class DequeEmptyException
{
public:
    DequeEmptyException()
    {
        std::cout << "Deque empty\n";
    }
};





