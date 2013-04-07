#pragma once
#include <iostream>

// Each node in a doubly linked list

class DequeEmptyException
{
public:
    DequeEmptyException()
    {
        std::cout << "Deque empty\n";
    }
};
template <class T> class Deque_iterator;
template<class T>
class deque
{
	struct Item
    {
       T data;
       Item* next;
       Item* prev;
    };
	public:
		typedef Deque_iterator<T> iterator;
		deque():head(NULL),tail(NULL),count(0){}
		deque(const deque<T> & deque);
		~deque(){}
		
		void push_front(T value);
	    T pop_front();
        void push_back(T value);
        T pop_back();
		
		//ELEMENT ACCESS////
        T front();
		T back();
        unsigned int size() const;
		bool empty();
		void clear(){return;}

    private:
		 Item* head;
		 Item*  tail;
	     int count;
    
};
template <class T>
void deque<T>::push_back(T  value)
{
	// Create a new node
			Item* temp = new Item();
			temp->data = value;
			temp->next = NULL;
			temp->prev = NULL;

			if ( empty() ) {
				// Add the first element
				 head = tail = temp;
			}
			else {
				// Append to the list and fix links
				 tail->next = temp;
				 temp->prev = tail;
				 tail = temp;
			 }

			count++; 
}
template <class T>
void deque<T>::push_front(T  value)
{
	// Create a new node
			Item* temp = new Item();
			temp->data = value;
			temp->next = NULL;
			temp->prev = NULL;

			if ( empty() ) {
				 // Add the first element
				head = tail = temp;
			 }
			else {
            // Prepend to the list and fix links
            temp->next = head;
            head->prev = temp;
            head = temp;
			}

			count++;
}
template <class T>
T deque<T>::pop_front()
{
	if ( empty() ) {
            throw new DequeEmptyException();
			}

			 //  Data in the head node
			T ret = head->data;

			// Delete the head node and fix the links
			Item* tmp = head;
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
template <class T>
T deque<T>::pop_back()
{
	if ( empty() ) {
            throw new DequeEmptyException();
			}

			//  Data in the tail node
			T ret = tail->data;

			// Delete the head node and fix the links
			Item* temp = tail;
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
		    delete temp;

			return ret;
}
template <class T>
unsigned int deque<T>::size() const
{
	return count;
}
template <class T>
bool deque<T>::empty()
{
	return count == 0;
}
template <class T>
T deque<T>::front()
{
	if ( empty() )
				throw new DequeEmptyException();
	return head->data;
}
template <class T>
T deque<T>::back()
{
	if ( empty() )
				throw new DequeEmptyException();
	return tail->data;
}


