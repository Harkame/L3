#ifndef MONEXCEPTION_H
#define MONEXCEPTION_H

#include <exception>


class MonException : exception
{
	public:
	virtual const char* message() const throw()
  {
      return "La pile est vide !";
  }
};

#endif
