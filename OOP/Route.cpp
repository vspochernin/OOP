#include <iomanip>

#include "Route.h"
#include "MyExceptions.h"

#pragma region ������������ � ����������.
// ����������� ��� ����������.
Route::Route() : start_(""), finish_("� ����"), routeNumber_(0) {}

// ����������� � �����������.
Route::Route(const std::string& start, const std::string& finish, int routeNumber) : start_(start), finish_(finish), routeNumber_(routeNumber)
{
	if (routeNumber_ <= 0)
	{
		throw InvalidRoute("������������ ����� �������.");
	}
	if ((start_ == "") || (finish_ == ""))
	{
		throw InvalidRoute("������ �������� ������� ��������.");
	}
}

// ����������� �����������.
Route::Route(const Route& route) : start_(route.start_), finish_(route.finish_), routeNumber_(route.routeNumber_)
{
	if (routeNumber_ <= 0)
	{
		throw InvalidRoute("������������ ����� ������� ��� �����������.");
	}
	if ((start_ == "") || (finish_ == ""))
	{
		throw InvalidRoute("������ �������� ������� �������� ��� �����������.");
	}
}

// ����������.
Route::~Route() {}
#pragma endregion

#pragma region ������� � �������.
// �������� �������� ���������� ������ ��������.
std::string Route::getStart() const
{
	return start_;
}

// �������� �������� ��������� ������ ��������.
std::string Route::getFinish() const
{
	return finish_;
}

// �������� ����� ��������.
int Route::getRouteNumber() const
{
	return routeNumber_;
}

// ���������� �������� ���������� ������ ��������.
void Route::setStart(const std::string& start)
{
	start_ = start;
	if (start_ == "")
	{
		throw(InvalidRoute("������ �������� ������ ��������."));
	}
}

// ���������� �������� ��������� ������ ��������.
void Route::setFinish(const std::string& finish)
{
	finish_ = finish;
	if (finish_ == "")
	{
		throw(InvalidRoute("������ �������� ����� ��������."));
	}
}

// ���������� ����� ��������.
void Route::setRouteNumber(int routeNumber)
{
	routeNumber_ = routeNumber;
	if (routeNumber_ <= 0)
	{
		throw(InvalidRoute("������������ ����� �������."));
	}
}

// ���������� ������� � ������� � ����.
void Route::toThePark()
{
	start_ = "";
	finish_ = "� ����";
	routeNumber_ = 0;
}
#pragma endregion


#pragma region ���������� �������� ���������� (����, ������� ����� �����). 
// ���������� ��������� ������������.
Route Route::operator= (const Route& route2)
{
	if (this == &route2)
	{
		return *this;
	}

	start_ = route2.start_;
	finish_ = route2.finish_;
	routeNumber_ = route2.routeNumber_;

	if (routeNumber_ <= 0)
	{
		throw InvalidRoute("������������ ����� ������� ��� ������������.");
	}
	if ((start_ == "") || (finish_ == ""))
	{
		throw InvalidRoute("������ �������� ������� �������� ��� ������������.");
	}

	return *this;
}

// ���������� ��������� ���������.
bool Route::operator==(const Route& route2) const
{
	return ((start_ == route2.start_) && (finish_ == route2.finish_) && (routeNumber_ == route2.routeNumber_));
}

// ���������� ��������� �����������.
bool Route::operator!=(const Route& route2) const
{
	return ((start_ != route2.start_) || (finish_ != route2.finish_) || (routeNumber_ != route2.routeNumber_));
}

// ���������� �������� ������.
bool Route::operator>(const Route& route2) const
{
	return (routeNumber_ > route2.routeNumber_);
}

// ���������� �������� ������.
bool Route::operator<(const Route& route2) const
{
	return (routeNumber_ < route2.routeNumber_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator>=(const Route& route2) const
{
	return (routeNumber_ >= route2.routeNumber_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator<=(const Route& route2) const
{
	return (routeNumber_ <= route2.routeNumber_);
}
#pragma endregion

#pragma region ���������� ++ -- � ������.
// ���������� ��������� ����������� ����������.
Route Route::operator++()
{
	routeNumber_ += 1;
	return *this;
}

// ���������� ��������� ������������ ����������.
Route Route::operator++(int notused)
{
	Route temp = Route(*this);
	routeNumber_ += 1;
	return temp;
}

// ���������� ��������� ����������� ����������.
Route Route::operator--()
{
	routeNumber_ -= 1;
	return *this;
}

// ���������� ��������� ������������ ����������.
Route Route::operator--(int notused)
{
	Route temp = Route(*this);
	routeNumber_ -= 1;
	return temp;
}

// ���������� ��������� <<. 
std::ostream& operator<< (std::ostream& out, const Route& route)
{
	return (out << '|' << std::setw(14) << route.routeNumber_ << '|' << std::setw(15) << route.start_ << '|' << std::setw(14) << route.finish_ << '|');
}

// ���������� ��������� >>.
std::istream& operator>> (std::istream& in, Route& route)
{
	return (in >> route.routeNumber_ >> route.start_ >> route.finish_);
}
#pragma endregion

