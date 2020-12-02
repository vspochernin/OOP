#include <iomanip>
#include "Route.h"
#include "MyExceptions.h"

#pragma region Конструкторы и деструктор.
// Конструктор без параметров.
Route::Route() : start_(""), finish_("В парк"), routeNumber_(0) {}

// Конструктор с параметрами.
Route::Route(const std::string& start, const std::string& finish, int routeNumber) : start_(start), finish_(finish), routeNumber_(routeNumber)
{
	if (routeNumber_ <= 0)
	{
		throw InvalidRoute("Неправильный номер машрута.");
	}
	if ((start_ == "") || (finish_ == ""))
	{
		throw InvalidRoute("Пустое название пунктов маршрута.");
	}
}

// Конструктор копирования.
Route::Route(const Route& r) : start_(r.start_), finish_(r.finish_), routeNumber_(r.routeNumber_)
{
	if (routeNumber_ <= 0)
	{
		throw InvalidRoute("Неправильный номер машрута при копировании.");
	}
	if ((start_ == "") || (finish_ == ""))
	{
		throw InvalidRoute("Пустое название пунктов маршрута при копировании.");
	}
}

// Деструктор.
Route::~Route() {}
#pragma endregion

#pragma region Геттеры и сеттеры.
// Получить название начального пункта маршрута.
std::string Route::getStart() const
{
	return start_;
}

// Получить название конечного пункта маршрута.
std::string Route::getFinish() const
{
	return finish_;
}

// Получить номер маршрута.
int Route::getRouteNumber() const
{
	return routeNumber_;
}

// Установить название начального пункта маршрута.
void Route::setStart(const std::string& start)
{
	start_ = start;
	if (start_ == "")
	{
		throw(InvalidRoute("Пустое название начала маршрута."));
	}
}

// Установить название конечного пункта маршрута.
void Route::setFinish(const std::string& finish)
{
	finish_ = finish;
	if (finish_ == "")
	{
		throw(InvalidRoute("Пустое название конца маршрута."));
	}
}

// Установить номер маршрута.
void Route::setRouteNumber(int routeNumber)
{
	routeNumber_ = routeNumber;
	if (routeNumber_ <= 0)
	{
		throw(InvalidRoute("Неправильный номер машрута."));
	}
}

// Превратить маршрут в маршрут в парк.
void Route::toThePark()
{
	start_ = "";
	finish_ = "В парк";
	routeNumber_ = 0;
}
#pragma endregion


#pragma region Перегрузка бинарных операторов (всех, которые имеют смысл). 
// Перегрузка оператора присваивания.
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
		throw InvalidRoute("Неправильный номер машрута при присваивании.");
	}
	if ((start_ == "") || (finish_ == ""))
	{
		throw InvalidRoute("Пустое название пунктов маршрута при присваивании.");
	}

	return *this;
}

// Перегрузка опреатора равенства.
bool Route::operator==(const Route& r2) const
{
	return ((start_ == r2.start_) && (finish_ == r2.finish_) && (routeNumber_ == r2.routeNumber_));
}

// Перегрузка опреатора неравенства.
bool Route::operator!=(const Route& r2) const
{
	return ((start_ != r2.start_) || (finish_ != r2.finish_) || (routeNumber_ != r2.routeNumber_));
}

// Перегрузка опретора больше.
bool Route::operator>(const Route& r2) const
{
	return (routeNumber_ > r2.routeNumber_);
}

// Перегрузка опретора меньше.
bool Route::operator<(const Route& r2) const
{
	return (routeNumber_ < r2.routeNumber_);
}

// Перегрузка опретора больше или равно.
bool Route::operator>=(const Route& r2) const
{
	return (routeNumber_ >= r2.routeNumber_);
}

// Перегрузка опретора меньше или равно.
bool Route::operator<=(const Route& r2) const
{
	return (routeNumber_ <= r2.routeNumber_);
}
#pragma endregion

#pragma region Перегрузка ++ -- и потока.
// Перегрузка оператора префиксного инкремента.
Route Route::operator++()
{
	routeNumber_ += 1;
	return *this;
}

// Перегрузка оператора постфиксного инкремента.
Route Route::operator++(int notused)
{
	Route temp = Route(*this);
	routeNumber_ += 1;
	return temp;
}

// Перегрузка оператора префиксного декремента.
Route Route::operator--()
{
	routeNumber_ -= 1;
	return *this;
}

// Перегрузка оператора постфиксного декремента.
Route Route::operator--(int notused)
{
	Route temp = Route(*this);
	routeNumber_ -= 1;
	return temp;
}

// Перегрузка оператора <<. 
std::ostream& operator<< (std::ostream& out, const Route& r)
{
	return (out << '|' << std::setw(14) << r.routeNumber_ << '|' << std::setw(15) << r.start_ << '|' << std::setw(14) << r.finish_ << '|');
}

// Перегрузка оператора >>.
std::istream& operator>> (std::istream& in, Route& r)
{
	return (in >> r.routeNumber_ >> r.start_ >> r.finish_);
}
#pragma endregion

