#include <iomanip>
#include "Route.h"

#pragma region ������������ � ����������.
// ����������� ��� ����������.
Route::Route() : start_(""), finish_(""), routeNumber_(0) {}

// ����������� � �����������.
Route::Route(const std::string& start, const std::string& finish, int routeNumber) : start_(start), finish_(finish), routeNumber_(routeNumber) {}

// ����������� �����������.
Route::Route(const Route& r) : start_(r.start_), finish_(r.finish_), routeNumber_(r.routeNumber_) {}

// ����������.
Route::~Route() {}
#pragma endregion

#pragma region ������� � �������.
// �������� �������� ���������� ������ ��������.
std::string Route::getStart() const
{
	return this->start_;
}

// �������� �������� ��������� ������ ��������.
std::string Route::getFinish() const
{
	return this->finish_;
}

// �������� ����� ��������.
unsigned int Route::getRouteNumber() const
{
	return this->routeNumber_;
}

// ���������� �������� ���������� ������ ��������.
void Route::setStart(const std::string& start)
{
	this->start_ = start;
}

// ���������� �������� ��������� ������ ��������.
void Route::setFinish(const std::string& finish)
{
	this->finish_ = finish;
}

// ���������� ����� ��������.
void Route::setRouteNumber(unsigned int routeNumber)
{
	this->routeNumber_ = routeNumber;
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
	this->start_ = r2.start_;
	this->finish_ = r2.finish_;
	this->routeNumber_ = r2.routeNumber_;
	return *this;
}

// ���������� ��������� ���������.
bool Route::operator==(const Route& r2) const
{
	return ((this->start_ == r2.start_) && (this->finish_ == r2.finish_) && (this->routeNumber_ == r2.routeNumber_));
}

// ���������� ��������� �����������.
bool Route::operator!=(const Route& r2) const
{
	return ((this->start_ != r2.start_) || (this->finish_ != r2.finish_) || (this->routeNumber_ != r2.routeNumber_));
}

// ���������� �������� ������.
bool Route::operator>(const Route& r2) const
{
	return (this->routeNumber_ > r2.routeNumber_);
}

// ���������� �������� ������.
bool Route::operator<(const Route& r2) const
{
	return (this->routeNumber_ < r2.routeNumber_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator>=(const Route& r2) const
{
	return (this->routeNumber_ >= r2.routeNumber_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator<=(const Route& r2) const
{
	return (this->routeNumber_ <= r2.routeNumber_);
}
#pragma endregion

#pragma region ���������� ++ -- � ������.
// ���������� ��������� ����������� ����������.
Route Route::operator++()
{
	this->routeNumber_ += 1;
	return *this;
}

// ���������� ��������� ������������ ����������.
Route Route::operator++(int notused)
{
	Route temp = Route(*this);
	this->routeNumber_ += 1;
	return *this;
}

// ���������� ��������� ����������� ����������.
Route Route::operator--()
{
	this->routeNumber_ -= 1;
	return *this;
}

// ���������� ��������� ������������ ����������.
Route Route::operator--(int notused)
{
	Route temp = Route(*this);
	this->routeNumber_ -= 1;
	return *this;
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

