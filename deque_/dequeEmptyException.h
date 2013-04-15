#pragma once
#include <stdexcept>
class DequeEmptyException : public std::exception
{
  public :
	DequeEmptyException():std::exception() {};
	DequeEmptyException(std::string message):std::exception(message.c_str()){}
 ;
};

