#pragma once
#include <iostream>

// Each node in a doubly linked list

class DequeEmptyException;
template <class T> class deque_iterator;
template<class T>
class deque
{
	struct Node
    {
       T data;
       Node* next;
       Node* prev;
    };
	public:
		typedef deque_iterator<T> iterator;
		deque();//так как define NULL=0
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
		bool empty() const;
		void clear(){return;}

    private:
		 Node* head;
		 Node*  tail;
	     int size_of_deque ;
    
};
template <class T>
deque<T>::deque()
{
	head = NULL;
	tail = NULL;
	size_of_deque = NULL;
	
}
template <class T>
deque<T>::deque(const deque & dek)
{
	deque();
	for (Node<T> * current = dek.head; current != NULL; current = current ->next)
                push_back(current -> value);
}
template <class T>
void deque<T>::push_back(T  value)
{
	// Create a new node
			Node* temp = new Node();
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

			size_of_deque++; 
}
template <class T>
void deque<T>::push_front(T  value)
{
	// Create a new node
			Node* temp = new Node();
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

			size_of_deque++;
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
			size_of_deque--;
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
			Node* temp = tail;
			if ( tail->prev != NULL )
		    {
				 tail = tail->prev;
				 tail->next = NULL;
            }
			else
			{
			   tail = NULL;
			}
            size_of_deque--;
		    delete temp;

			return ret;
}
template <class T>
unsigned int deque<T>::size() const
{
	return size_of_deque;
}
template <class T>
bool deque<T>::empty() const
{
	return size_of_deque == 0;
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

class DequeEmptyException
{
public:
    DequeEmptyException()
    {
        std::cout << "Deque empty\n";
    }
};

