#ifndef MY_EXCEPTIONS
#define MY_EXCEPTIONS

// Классы исключений.

#include <string>
#include <exception>

class InvalidRoute : public std::exception
{
private:
  std::string errorMessage_;
public:
  InvalidRoute(std::string errorMessage) : errorMessage_(errorMessage) {}

  virtual const char* what() const noexcept
  {
    return errorMessage_.c_str();
  }
};

#endif
