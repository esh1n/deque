#include "stdafx.h"
#include "deque.h"

deque::deque()
{
    front = NULL;
    back = NULL;
    count = 0;
}      
  
void deque::InsertFront(int element)
{
        // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() ) {
            // Add the first element
            front = back = tmp;
        }
        else {
            // Prepend to the list and fix links
            tmp->next = front;
            front->prev = tmp;
            front = tmp;
        }

        count++;
}

int deque::RemoveFront()
{
	if ( isEmpty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the front node
        int ret = front->data;

        // Delete the front node and fix the links
        Node* tmp = front;
        if ( front->next != NULL )
        {
            front = front->next;
            front->prev = NULL;
        }
        else
        {
            front = NULL;
        }
        count--;
        delete tmp;

        return ret;
       
}

void deque::InsertBack(int element)
{ // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() ) {
            // Add the first element
            front = back = tmp;
        }
        else {
            // Append to the list and fix links
            back->next = tmp;
            tmp->prev = back;
            back = tmp;
        }

        count++; 
}    

int deque::RemoveBack()
{
	if ( isEmpty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the back node
        int ret = back->data;

        // Delete the front node and fix the links
        Node* tmp = back;
        if ( back->prev != NULL )
        {
            back = back->prev;
            back->next = NULL;
        }
        else
        {
            back = NULL;
        }
        count--;
        delete tmp;

        return ret;
        
}   
  
int deque::Front()
{          
   if ( isEmpty() )
        throw new DequeEmptyException();
   return front->data;
}

int deque::Back()
{
   if ( isEmpty() )
        throw new DequeEmptyException();
   return back->data;
}
  
int deque::Size()
{
   return count;
}

bool deque::isEmpty()
{
   return count == 0 ? true : false;
}
deque::~deque(void)
{
}


