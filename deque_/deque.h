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
		void push_front(int element);
        int pop_front();
        void push_back(int element);
        int pop_back();
        int front();
        int back();
        int size();
        bool empty();

    private:
		 Node *head;
		 Node* tail;
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





