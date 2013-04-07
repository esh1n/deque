#include "stdafx.h"
#include "deque.h"

deque::deque()
{
    head = NULL;
    tail = NULL;
    count = 0;
}      
  
void deque::push_front(int element)
{
        // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( empty() ) {
            // Add the first element
            head = tail = tmp;
        }
        else {
            // Prepend to the list and fix links
            tmp->next = head;
            head->prev = tmp;
            head = tmp;
        }

        count++;
}

int deque::pop_front()
{
	if ( empty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the head node
        int ret = head->data;

        // Delete the head node and fix the links
        Node* tmp = head;
        if ( head->next != NULL )
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            head = NULL;
        }
        count--;
        delete tmp;

        return ret;
       
}

void deque::push_back(int element)
{ // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( empty() ) {
            // Add the first element
            head = tail = tmp;
        }
        else {
            // Append to the list and fix links
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }

        count++; 
}    

int deque::pop_back()
{
	if ( empty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the tail node
        int ret = tail->data;

        // Delete the head node and fix the links
        Node* tmp = tail;
        if ( tail->prev != NULL )
        {
            tail = tail->prev;
            tail->next = NULL;
        }
        else
        {
            tail = NULL;
        }
        count--;
        delete tmp;

        return ret;
        
}   
  
int deque::front()
{          
   if ( empty() )
        throw new DequeEmptyException();
   return head->data;
}

int deque::back()
{
   if ( empty() )
        throw new DequeEmptyException();
   return tail->data;
}
  
int deque::size()
{
   return count;
}
bool deque::empty()
{
   return count == 0 ? true : false;
}
deque::~deque(void)
{
}


