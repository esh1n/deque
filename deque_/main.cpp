
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
	 // Stack behavior using a general dequeue
    deque q;
    try {
        if ( q.empty() )
        {
            std::tcout << "Deque is empty\n";
        }

        // Push elements
        q.push_back(100);
        q.push_back(200);
        q.push_back(300);

        // size of queue
        std::tcout << "size of dequeue = " << q.size()<<"\n";

        // Pop elements
        std::tcout << q.pop_back() <<"\n";
        std::tcout << q.pop_back() <<"\n";
        std::tcout << q.pop_back() <<"\n";
    }
    catch (...) {
        std::tcout << "Some exception occured" <<"\n"; 
    }

    // Queue behavior using a general dequeue
    deque q1;
    try {
        if ( q1.empty() )
        {
            std::tcout << "\nDeque is empty";
        }

        // Push elements
        q1.push_back(100);
        q1.push_back(200);
        q1.push_back(300);

        // size of queue
        std::tcout << "size of dequeue = " << q1.size() << "\n";

        // Pop elements
		
        std::tcout << q1.pop_front() << "\n";
        std::tcout << q1.pop_front() << "\n";
        std::tcout << q1.pop_front() << "\n";
    }
    catch (...) {
        std::tcout << "Some exception occured" <<"\n";
    }
	int i;
	std::tcin>>i;
	return 0;
}

