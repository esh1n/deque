
#include "stdafx.h"
void printDeque(deque<std::wstring> deq)
{
	std::tcout<< "\n";
   deque<std::wstring>::iterator itr(deq.begin());
   while (itr != deq.end()) {
	   std::tcout << (*itr).c_str() << "\n";
        ++itr;
   }
   std::tcout << (*itr).c_str() << "\n\n";
}
void printDeque(deque<int> deq)
{
	std::tcout<< "\n";
   deque<int>::iterator itr(deq.begin());
   while (itr != deq.end()) {
	   std::tcout << (*itr) << "\n";
        ++itr;
   }
   std::tcout << (*itr) << "\n\n";
}
int _tmain(int argc, _TCHAR* argv[])
{
	deque<int> deq_3(3,3);
	printDeque(deq_3);
	deque<std::wstring> deq_1;

   deq_1.push_back(_T("and"));  
   deq_1.push_front(_T("Love")); 
   deq_1.push_back(_T("Peace"));    

   deque<std::wstring> deq_2(deq_1);
   
   
   bool loop=false;
   int index=0;
   std::tcout<<"\0-exit\n";
   std::tcout<<"1-push_back\n";
   std::tcout<<"2-push_front\n";
   std::tcout<<"3-pop_back\n";
   std::tcout<<"4-pop_front\n";
   std::tcout<<"5-[index] or at\n";
   
	/////process/////////////////
	do
	{
		   printDeque(deq_2);
		   TCHAR operation;
		   std::wstring arg;
		   std::tcin>> operation>>arg; 
		   switch (operation)
		   {
		   case '1':
			   deq_2.push_back(arg);
			   break;
		   case '2':
			   deq_2.push_front(arg);
			   break;
		   case '3':
			   deq_2.pop_back();
			   break;
		   case '4':
			   deq_2.pop_front();
			   break;
		   case '5':
			   index=_tstoi(arg.c_str());
			   std::tcout << (deq_2[index]).c_str() << "\n";
			   break;
		   default:
			   break;
		   }
           loop= (operation!='0') ;
	}while(loop);
	return 0;
}

