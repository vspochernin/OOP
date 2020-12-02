#ifndef ROUTE
#define ROUTE

#include <iostream>
#include <string>

class Route
{
private:
  std::string start_; // Название начального пункта маршрута.
  std::string finish_; // Название конечного пункта маршрута.
  int number_; // Номер маршрута.
public:
#pragma region Конструкторы и деструктор.
  // Конструктор без параметров.
  Route();

  // Конструктор с параметрами.
  Route(const std::string& start, const std::string& finish, int number);

  // Конструктор копирования.
  Route(const Route& route);

  // Деструктор.
  ~Route();
#pragma endregion

#pragma region Геттеры и сеттеры.
  // Получить название начального пункта маршрута.
  std::string getStart() const;

  // Получить название конечного пункта маршрута.
  std::string getFinish() const;

  // Получить номер маршрута.
  int getNumber() const;

  // Установить название начального пункта маршрута.
  void setStart(const std::string& start);

  // Установить название конечного пункта маршрута.
  void setFinish(const std::string& finish);

  // Установить номер маршрута.
  void setNumber(int number);

  // Превратить маршрут в маршрут в парк.
  void toThePark();
#pragma endregion

#pragma region Перегрузка бинарных операторов (всех, которые имеют смысл). 
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
#pragma endregion

#pragma region Перегрузка ++ -- и потока.
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
#pragma endregion
};

#endif