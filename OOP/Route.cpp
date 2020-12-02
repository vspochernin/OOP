#include <iomanip>

#include "Route.h"
#include "MyExceptions.h"

#ifdef _MSC_VER
#pragma region ������������ � ����������.
#endif
// ����������� ��� ����������.
Route::Route() : start_(""), finish_("� ����"), number_(0) {}

// ����������� � �����������.
Route::Route(const std::string& start, const std::string& finish, int number) : start_(start), finish_(finish), number_(number)
{
  if (number_ <= 0)
  {
    throw InvalidRoute("������������ ����� �������.");
  }
  if ((start_ == "") || (finish_ == ""))
  {
    throw InvalidRoute("������ �������� ������� ��������.");
  }
}

// ����������� �����������.
Route::Route(const Route& route) : start_(route.start_), finish_(route.finish_), number_(route.number_)
{
  if (number_ <= 0)
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
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region ������� � �������.
#endif
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
int Route::getNumber() const
{
  return number_;
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
void Route::setNumber(int number)
{
  number_ = number;
  if (number_ <= 0)
  {
    throw(InvalidRoute("������������ ����� �������."));
  }
}

// ���������� ������� � ������� � ����.
void Route::toThePark()
{
  start_ = "";
  finish_ = "� ����";
  number_ = 0;
}
#ifdef _MSC_VER
#pragma endregion
#endif


#ifdef _MSC_VER
#pragma region ���������� �������� ���������� (����, ������� ����� �����). 
#endif
// ���������� ��������� ������������.
Route Route::operator= (const Route& route2)
{
  if (this == &route2)
  {
    return *this;
  }

  start_ = route2.start_;
  finish_ = route2.finish_;
  number_ = route2.number_;

  if (number_ <= 0)
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
  return ((start_ == route2.start_) && (finish_ == route2.finish_) && (number_ == route2.number_));
}

// ���������� ��������� �����������.
bool Route::operator!=(const Route& route2) const
{
  return ((start_ != route2.start_) || (finish_ != route2.finish_) || (number_ != route2.number_));
}

// ���������� �������� ������.
bool Route::operator>(const Route& route2) const
{
  return (number_ > route2.number_);
}

// ���������� �������� ������.
bool Route::operator<(const Route& route2) const
{
  return (number_ < route2.number_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator>=(const Route& route2) const
{
  return (number_ >= route2.number_);
}

// ���������� �������� ������ ��� �����.
bool Route::operator<=(const Route& route2) const
{
  return (number_ <= route2.number_);
}
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region ���������� ++ -- � ������.
#endif
// ���������� ��������� ����������� ����������.
Route Route::operator++()
{
  number_ += 1;
  return *this;
}

// ���������� ��������� ������������ ����������.
Route Route::operator++(int notused)
{
  Route temp = Route(*this);
  number_ += 1;
  return temp;
}

// ���������� ��������� ����������� ����������.
Route Route::operator--()
{
  number_ -= 1;
  return *this;
}

// ���������� ��������� ������������ ����������.
Route Route::operator--(int notused)
{
  Route temp = Route(*this);
  number_ -= 1;
  return temp;
}

// ���������� ��������� <<. 
std::ostream& operator<< (std::ostream& out, const Route& route)
{
  return (out << '|' << std::setw(14) << route.number_ << '|' << std::setw(15) << route.start_ << '|' << std::setw(14) << route.finish_ << '|');
}

// ���������� ��������� >>.
std::istream& operator>> (std::istream& in, Route& route)
{
  return (in >> route.number_ >> route.start_ >> route.finish_);
}
#ifdef _MSC_VER
#pragma endregion
#endif

