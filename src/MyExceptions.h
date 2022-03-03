#ifndef MY_EXCEPTIONS
#define MY_EXCEPTIONS

// Классы исключений.

#include <exception>
#include "MyString.h"

class InvalidRoute : public std::exception
{
private:
  MyString errorMessage_;
public:
  InvalidRoute(MyString errorMessage) : errorMessage_(errorMessage) {}

  virtual const char* what() const noexcept
  {
    return errorMessage_.get();
  }
};

class InvalidInput : public std::exception
{
private:
  MyString errorMessage_;
public:
  InvalidInput(MyString errorMessage) : errorMessage_(errorMessage) {}

  virtual const char* what() const noexcept
  {
    return errorMessage_.get();
  }
};


#endif