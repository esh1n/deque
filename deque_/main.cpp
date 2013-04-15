
#include "stdafx.h"
void printDeque(deque<std::wstring> deq)
{
	std::tcout<< "\n";
   deque<std::wstring>::reverse_iterator itr(deq.rbegin());
   while (itr != deq.end()) {
	   std::tcout << (*itr).c_str() << "\n";
        ++itr;
   }
   std::tcout << (*itr).c_str() << "\n\n";
}

int _tmain(int argc, _TCHAR* argv[])
{
   deque<std::wstring> deq_1(5,_T("sample"));
   deque<std::wstring> deq_2(deq_1);
   bool loop=false;
   int index=0;
   std::tcout<<"\0-exit\n";
   std::tcout<<"1-push_back\n";
   std::tcout<<"2-push_front\n";
   std::tcout<<"3-pop_back\n";
   std::tcout<<"4-pop_front\n";
   std::tcout<<"5-[index] or at\n";
   std::tcout<<"6-reverse\n";
   std::tcout<<"7-back\n";
   std::tcout<<"8-front\n";
   std::tcout<<"9-size\n";
   std::tcout<<"10-clear\n";
   int iOperation=1;
	/////process/////////////////
	do
	{
		if(!deq_2.empty())
		   printDeque(deq_2);
		else   
		{
				std::tcout <<"\ndeq is empty\n";
			
		}
		   std::wstring operation;
		   std::wstring arg;
		   std::tcin>> operation>>arg; 
		   iOperation= _tstoi(operation.c_str());
		   switch (iOperation)
		   {
		   case 1:
			   deq_2.push_back(arg);
			   break;
		   case 2:
			   deq_2.push_front(arg);
			   break;
		   case 3:
			   try
			   {
					deq_2.pop_back();
			   }
			   catch(DequeEmptyException ex)
			   {
				   std::tcout<<ex.what();
			   }
			   break;
		   case 4:
			    try
			    {
					deq_2.pop_front();
			    }
			    catch(DequeEmptyException& ex)
			    {
				   std::tcout<<ex.what();
			    }
			   break;
		   case 5:
			   index=_tstoi(arg.c_str());
			   try
			   {
					std::tcout <<"\n"<< (deq_2[index]).c_str() << "\n";
			   }
			   catch(std::invalid_argument ex)
			   {
					std::tcout<<ex.what();
			   }
			   break;
		   case 6:
			   deq_2.reverse();
			   break;
          case 7:
			   std::tcout <<"\n"<< (deq_2.back()).c_str() << "\n";
			   break;
		  case 8:
			   std::tcout <<"\n"<< (deq_2.front()).c_str() << "\n";
			   break;
		  case 9:
			  std::tcout <<"\n"<< deq_2.size() << "\n";
			   break;
		  case 10:
				deq_2.clear() ;
				std::tcout <<"\n\n";
			   break;
		   default:
			   break;
		   }
           loop= operation.compare(_T("0")) ;
	}while(loop);
	return 0;
}

