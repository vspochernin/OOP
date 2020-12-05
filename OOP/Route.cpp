#include <iomanip>

#include "Route.h"
#include "MyExceptions.h"
#include "Functions.h"

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
    throw InvalidRoute("Неправильный номер машрута.");
  }
  if ((start_ == "") || (finish_ == ""))
  {
    throw InvalidRoute("Пустое название пунктов маршрута.");
  }
}

// Конструктор копирования.
Route::Route(const Route& route) : start_(route.start_), finish_(route.finish_), number_(route.number_)
{
  if (number_ <= 0)
  {
    throw InvalidRoute("Неправильный номер машрута при копировании.");
  }
  if ((start_ == "") || (finish_ == ""))
  {
    throw InvalidRoute("Пустое название пунктов маршрута при копировании.");
  }
}

// TODO: Деструктор.  Надо ли здесь очищать память строки? Или она очистится своим деструктором?
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
  if (start_ == "")
  {
    throw(InvalidRoute("Пустое название начала маршрута."));
  }
}

// Установить название конечного пункта маршрута.
void Route::setFinish(const MyString& finish)
{
  finish_ = finish;
  if (finish_ == "")
  {
    throw(InvalidRoute("Пустое название конца маршрута."));
  }
}

// Установить номер маршрута.
void Route::setNumber(int number)
{
  number_ = number;
  if (number_ <= 0)
  {
    throw(InvalidRoute("Неправильный номер машрута."));
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
    throw InvalidRoute("Неправильный номер машрута при присваивании.");
  }
  if ((start_ == "") || (finish_ == ""))
  {
    throw InvalidRoute("Пустое название пунктов маршрута при присваивании.");
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

// TODO: Перегрузка оператора >>. Вот это проверить, если будут баг.
// TODO: Проверить, правильно ли возвращаю?
std::istream& operator>> (std::istream& in, Route& route)
{
  // TODO: достаточно ли такой проверки?
  size_t number;
  MyString start;
  MyString finish;
  in >> number;
  if (!in || ((in.peek() != ' ') && in.peek() != '\n'))
  {
    throw (InvalidInput("Некоректный номер маршрута."));
  }
  in >> start;
  if (!in || !isCorrectRouteName(start))
  {
    throw (InvalidInput("Некорректное название начала маршрута."));
  }
  in >> finish;
  if ((!in.eof() && !in) || !isCorrectRouteName(finish))
  {
    throw (InvalidInput("Некорректное название конца маршрута."));
  }
  route.number_ = number;
  route.start_ = start;
  route.finish_ = finish;
  return in;
}
#ifdef _MSC_VER
#pragma endregion
#endif