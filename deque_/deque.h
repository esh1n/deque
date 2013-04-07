#pragma once
#include <iostream>

// Each node in a doubly linked list

class DequeEmptyException;
template <class T> class Node;
template <class T> class deque_iterator;
template<class T>
class deque
{
	
	public:
		typedef deque_iterator<T> iterator;
		deque();//так как define NULL=0
		deque(const deque<T> & deque);
		~deque();
		
		void push_front(const T & x);
	    T pop_front();
        void push_back(const T & x);
        T pop_back();
		
		//ELEMENT ACCESS////
        T front();
		T back();
		T* operator [](int i);
		
		void print_deque();
        unsigned int size() const;
		bool empty() const;
		void clear(){return;}
		iterator begin() const;
        iterator end() const;
    private:
		 Node<T>* head;
		 Node<T>*  tail;
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
	head = NULL;
	tail = NULL;
	size_of_deque = NULL;
	for (Node<T> * current = dek.head; current != NULL; current = current ->next_node)
		push_back(current -> data);
}
template <class T>
void deque<T>::print_deque()
{
    
}
template <class T>
deque <T>::~deque()
{
    Node <T> * first = head;
    while (first != 0)
    {
    Node <T> * next = first->next_node;
        delete first;
    first = next;
    }
}
/*template <class T>
T* deque<T>::operator [](int i)
    {// устанавливает текущим i-ый элемент и возвращает содержимое
     // этот список можно индексировать, хотя при больших размерах списка неэффективно
        if (_Set_by_Index(i))
            return Item->content;
        else
            return NULL;
    }*/
template <class T>
void deque<T>::push_back(const T & value)
{
	// Create a new node
			Node<T>* temp = new Node<T>(value);
		

		
			if (empty())
				head = tail = temp;
            else
            {
				temp->prev_node = tail;
				tail->next_node = temp;    
				tail = temp;
            }
			size_of_deque++;
}
template <class T>
void deque<T>::push_front(const T&  value)
{
	// Create a new node
			Node<T>* temp = new Node<T>(value);
			

			if ( empty() ) {
				 // Add the first element
				head = tail = temp;
			 }
			else {
            // Prepend to the list and fix links
            temp->next_node = head;
            head->prev_node = temp;
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
			Node<T>* tmp = head;
			if ( head->next_node != NULL )
			{
				head = head->next_node;
				head->prev_node = NULL;
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
			Node<T>* temp = tail;
			if ( tail->prev_node != NULL )
		    {
				 tail = tail->prev_node;
				 tail->next_node = NULL;
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
	return head == NULL;
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
template <class T>
typename deque<T>::iterator deque<T>::begin() const
{
        return iterator(head);
}
template <class T>
typename deque<T>::iterator deque<T>::end() const
{
        return iterator(tail);
}
/////CLASSES/////////////
class DequeEmptyException
{
public:
    DequeEmptyException()
    {
        std::cout << "Deque empty\n";
    }
};
template <class T> 
class Node 
{
private:
   Node(const T & x): data(x), next_node(0), prev_node(0) {}

   T data;     
   Node<T> * next_node;
   Node<T> * prev_node;

   friend class deque<T>;
   friend class deque_iterator<T>;
};
template <class T> class deque_iterator
{
public:
   typedef deque_iterator<T> iterator;

   deque_iterator(Node<T> * source_link): current_node(source_link) { }
   deque_iterator(): current_link(0) { }
   deque_iterator(deque_iterator<T> * source_iterator): current_node(source_iterator.current_node) { }

   T & operator*();  // оператор разыменования
   iterator & operator=(const iterator & rhs);
   bool operator==(const iterator & rhs) const;
   bool operator!=(const iterator & rhs) const;
   iterator & operator++(); 
   iterator operator++(int);
   iterator & operator--(); 
   iterator operator--(int); 

protected:
   Node<T> * current_node;

   friend class deque<T>;
};

template <class T>
T & deque_iterator<T>::operator*()
{
	return current_node -> data;
}

template <class T>
deque_iterator<T> & deque_iterator<T>::operator++()
{
        current_node = current_node -> next_node;
        return *this;
}
template<class T>
bool deque_iterator<T>::operator==(const iterator & rhs) const
{
    return ( this->current_node == rhs.current_node ); 
}

template <class T>
bool deque_iterator<T>::operator!=(const iterator & rhs) const
{
    return !( *this == rhs );
}

