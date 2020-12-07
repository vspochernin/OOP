#include <iomanip>

#include "Route.h"
#include "MyExceptions.h"
#include "Functions.h"
#include "ExceptionNames.h"

#ifdef _MSC_VER
#pragma region Конструкторы и деструктор.
#endif
// Конструктор без параметров.
Route::Route() : start_(""), finish_("В парк"), number_(0) {}

// Конструктор с параметрами.
Route::Route(const MyString& start, const MyString& finish, int number) : start_(start), finish_(finish), number_(number)
{
  if (number_ <= 0)
  {
    throw InvalidRoute(ERROR_INCORRECT_ROUTE_NUMBER);
  }
  if ((start_ == "") || (finish_ == ""))
  {
    throw InvalidRoute(ERROR_INCORRECT_ROUTE_POINTS_NAME);
  }
}

// Конструктор копирования.
Route::Route(const Route& route) : start_(route.start_), finish_(route.finish_), number_(route.number_)
{
  if (number_ <= 0)
  {
    throw InvalidRoute(ERROR_INCORRECT_ROUTE_NUMBER_WHEN_COPYING);
  }
  if ((start_ == "") || (finish_ == ""))
  {
    throw InvalidRoute(ERROR_INCORRECT_ROUTE_POINTS_NAME_WHEN_COPYING);
  }
}

Route::~Route() {}
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region Геттеры и сеттеры.
#endif
// Получить название начального пункта маршрута.
MyString Route::getStart() const
{
  return start_;
}

// Получить название конечного пункта маршрута.
MyString Route::getFinish() const
{
  return finish_;
}

// Получить номер маршрута.
int Route::getNumber() const
{
  return number_;
}

// Установить название начального пункта маршрута.
void Route::setStart(const MyString& start)
{
  start_ = start;
  if ((start_ == "") || !isCorrectRouteName(start_))
  {
    throw(InvalidRoute(ERROR_INCORRECT_ROUTE_START_NAME));
  }
}

// Установить название конечного пункта маршрута.
void Route::setFinish(const MyString& finish)
{
  finish_ = finish;
  if ((finish_ == "") || !isCorrectRouteName(finish_))
  {
    throw(InvalidRoute(ERROR_INCORRECT_ROUTE_FINISH_NAME));
  }
}

// Установить номер маршрута.
void Route::setNumber(int number)
{
  number_ = number;
  if (number_ <= 0)
  {
    throw(InvalidRoute(ERROR_INCORRECT_ROUTE_NUMBER));
  }
}

// Превратить маршрут в маршрут в парк.
void Route::toThePark()
{
  start_ = "";
  finish_ = "В парк";
  number_ = 0;
}
#ifdef _MSC_VER
#pragma endregion
#endif


#ifdef _MSC_VER
#pragma region Перегрузка бинарных операторов (всех, которые имеют смысл). 
#endif
// Перегрузка оператора присваивания.
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
    throw InvalidRoute(ERROR_INCORRECT_ROUTE_NUMBER_WHEN_ASSIGN);
  }
  if ((start_ == "") || (finish_ == ""))
  {
    throw InvalidRoute(ERROR_INCORRECT_ROUTE_POINTS_NAME_WHEN_ASSIGN);
  }

  return *this;
}

// Перегрузка опреатора равенства.
bool Route::operator==(const Route& route2) const
{
  return ((start_ == route2.start_) && (finish_ == route2.finish_) && (number_ == route2.number_));
}

// Перегрузка опреатора неравенства.
bool Route::operator!=(const Route& route2) const
{
  return ((start_ != route2.start_) || (finish_ != route2.finish_) || (number_ != route2.number_));
}

// Перегрузка опретора больше.
bool Route::operator>(const Route& route2) const
{
  return (number_ > route2.number_);
}

// Перегрузка опретора меньше.
bool Route::operator<(const Route& route2) const
{
  return (number_ < route2.number_);
}

// Перегрузка опретора больше или равно.
bool Route::operator>=(const Route& route2) const
{
  return (number_ >= route2.number_);
}

// Перегрузка опретора меньше или равно.
bool Route::operator<=(const Route& route2) const
{
  return (number_ <= route2.number_);
}
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region Перегрузка ++ -- и потока.
#endif
// Перегрузка оператора префиксного инкремента.
Route Route::operator++()
{
  number_ += 1;
  return *this;
}

// Перегрузка оператора постфиксного инкремента.
Route Route::operator++(int notused)
{
  Route temp = Route(*this);
  number_ += 1;
  return temp;
}

// Перегрузка оператора префиксного декремента.
Route Route::operator--()
{
  number_ -= 1;
  return *this;
}

// Перегрузка оператора постфиксного декремента.
Route Route::operator--(int notused)
{
  Route temp = Route(*this);
  number_ -= 1;
  return temp;
}

// Перегрузка оператора <<. 
std::ostream& operator<< (std::ostream& out, const Route& route)
{
  return (out << '|' << std::setw(14) << route.number_ << '|' << std::setw(15) << route.start_ << '|' << std::setw(14) << route.finish_ << '|');
}

std::istream& operator>> (std::istream& in, Route& route)
{
  size_t number;
  MyString start;
  MyString finish;
  in >> number;
  if (!in || ((in.peek() != ' ') && in.peek() != '\n'))
  {
    throw (InvalidInput(ERROR_INCORRECT_ROUTE_NUMBER));
  }
  in >> start;
  if (!in || !isCorrectRouteName(start))
  {
    throw (InvalidInput(ERROR_INCORRECT_ROUTE_START_NAME));
  }
  in >> finish;
  if ((!in.eof() && !in) || !isCorrectRouteName(finish))
  {
    throw (InvalidInput(ERROR_INCORRECT_ROUTE_FINISH_NAME));
  }
  route.number_ = number;
  route.start_ = start;
  route.finish_ = finish;
  return in;
}
#ifdef _MSC_VER
#pragma endregion
#endif