
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	 // Stack behavior using a general dequeue
    deque q;
    try {
        if ( q.isEmpty() )
        {
            std::tcout << "Deque is empty\n";
        }

        // Push elements
        q.InsertBack(100);
        q.InsertBack(200);
        q.InsertBack(300);

        // Size of queue
        std::tcout << "Size of dequeue = " << q.Size()<<"\n";

        // Pop elements
        std::tcout << q.RemoveBack() <<"\n";
        std::tcout << q.RemoveBack() <<"\n";
        std::tcout << q.RemoveBack() <<"\n";
    }
    catch (...) {
        std::tcout << "Some exception occured" <<"\n"; 
    }

    // Queue behavior using a general dequeue
    deque q1;
    try {
        if ( q1.isEmpty() )
        {
            std::tcout << "\nDeque is empty";
        }

        // Push elements
        q1.InsertBack(100);
        q1.InsertBack(200);
        q1.InsertBack(300);

        // Size of queue
        std::tcout << "Size of dequeue = " << q1.Size() << "\n";

        // Pop elements
		
        std::tcout << q1.RemoveFront() << "\n";
        std::tcout << q1.RemoveFront() << "\n";
        std::tcout << q1.RemoveFront() << "\n";
    }
    catch (...) {
        std::tcout << "Some exception occured" <<"\n";
    }
	int i;
	std::tcin>>i;
	return 0;
}

