// Классы исключений.
#pragma once

#include <exception>
#include <string>

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
