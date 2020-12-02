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
Route::Route(const Route& r) : start_(r.start_), finish_(r.finish_), routeNumber_(r.routeNumber_)
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
Route Route::operator= (const Route& r2)
{
	if (this == &r2)
	{
		return *this;
	}

	start_ = r2.start_;
	finish_ = r2.finish_;
	routeNumber_ = r2.routeNumber_;

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
bool Route::operator==(const Route& r2) const
{
	return ((start_ == r2.start_) && (finish_ == r2.finish_) && (routeNumber_ == r2.routeNumber_));
}

// ���������� ��������� �����������.
bool Route::operator!=(const Route& r2) const
{
	return ((start_ != r2.start_) || (finish_ != r2.finish_) || (routeNumber_ != r2.routeNumber_));
}

// ���������� �������� ������.
bool Route::operator>(const Route& r2) const
{
	return (routeNumber_ > r2.routeNumber_);
}

// ���������� �������� ������.
bool Route::operator<(const Route& r2) const
{
	return (routeNumber_ < r2.routeNumber_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator>=(const Route& r2) const
{
	return (routeNumber_ >= r2.routeNumber_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator<=(const Route& r2) const
{
	return (routeNumber_ <= r2.routeNumber_);
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
std::ostream& operator<< (std::ostream& out, const Route& r)
{
	return (out << '|' << std::setw(14) << r.routeNumber_ << '|' << std::setw(15) << r.start_ << '|' << std::setw(14) << r.finish_ << '|');
}

// ���������� ��������� >>.
std::istream& operator>> (std::istream& in, Route& r)
{
	return (in >> r.routeNumber_ >> r.start_ >> r.finish_);
}
#pragma endregion

