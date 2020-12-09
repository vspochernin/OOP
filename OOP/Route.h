#ifndef ROUTE
#define ROUTE

#include <iostream>
#include "MyString.h"

class Route
{
private:
  MyString start_; // Название начального пункта маршрута.
  MyString finish_; // Название конечного пункта маршрута.
  int number_; // Номер маршрута.
public:
#ifdef _MSC_VER
#pragma region Конструкторы и деструктор.
#endif
  // Конструктор без параметров.
  Route();

  // Конструктор с параметрами.
  Route(const MyString& start, const MyString& finish, int number);

  // Конструктор копирования.
  Route(const Route& route);

  // Деструктор.
  ~Route();
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region Геттеры и сеттеры.
#endif
  // Получить название начального пункта маршрута.
  MyString getStart() const;

  // Получить название конечного пункта маршрута.
  MyString getFinish() const;

  // Получить номер маршрута.
  int getNumber() const;

  // Установить название начального пункта маршрута.
  void setStart(const MyString& start);

  // Установить название конечного пункта маршрута.
  void setFinish(const MyString& finish);

  // Установить номер маршрута.
  void setNumber(int number);

  // Превратить маршрут в маршрут в парк.
  void toThePark();
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region Перегрузка бинарных операторов (всех, которые имеют смысл). 
#endif
  // Перегрузка оператора присваивания.
  Route operator= (const Route& route2);

  // Перегрузка опреатора равенства.
  bool operator==(const Route& route2) const;

  // Перегрузка опреатора неравенства.
  bool operator!=(const Route& route2) const;

  // Перегрузка опретора больше.
  bool operator>(const Route& route2) const;

  // Перегрузка опретора меньше.
  bool operator<(const Route& route2) const;

  // Перегрузка опретора больше или равно.
  bool operator>=(const Route& route2) const;

  // Перегрузка опретора меньше или равно.
  bool operator<=(const Route& route2) const;
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region Перегрузка ++ -- и потока.
#endif
  // Перегрузка оператора префиксного инкремента.
  Route operator++();
  // Перегрузка оператора постфиксного инкремента.
  Route operator++(int notused);

  // Перегрузка оператора префиксного декремента.
  Route operator--();
  // Перегрузка оператора постфиксного декремента.
  Route operator--(int notused);

  // Перегрузка оператора <<. 
  friend std::ostream& operator<< (std::ostream& out, const Route& route);

  // Перегрузка оператора >>.
  friend std::istream& operator>> (std::istream& in, Route& route);
#ifdef _MSC_VER
#pragma endregion
#endif
};

#endif