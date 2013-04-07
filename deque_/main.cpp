
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	deque<std::string> l;

   l.push_back("and");  
   l.push_front("Love");  // 
   l.push_back("Peace");    

   deque<std::string> m(l);

   deque<std::string>::iterator itr(m.begin());
   while (itr != m.end()) {
	   std::tcout << (*itr).c_str() << "\n";
        ++itr;
   }
   std::tcout << (*itr).c_str() << "\n";
   int i=0;
   std::tcin>>i;
	return 0;
}

