#ifndef ROUTE
#define ROUTE

#include <iostream>
#include "MyString.h"

class Route
{
private:
  MyString start_; // �������� ���������� ������ ��������.
  MyString finish_; // �������� ��������� ������ ��������.
  int number_; // ����� ��������.
public:
#ifdef _MSC_VER
#pragma region ������������ � ����������.
#endif
  // ����������� ��� ����������.
  Route();

  // ����������� � �����������.
  Route(const MyString& start, const MyString& finish, int number);

  // ����������� �����������.
  Route(const Route& route);

  // ����������.
  ~Route();
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region ������� � �������.
#endif
  // �������� �������� ���������� ������ ��������.
  MyString getStart() const;

  // �������� �������� ��������� ������ ��������.
  MyString getFinish() const;

  // �������� ����� ��������.
  int getNumber() const;

  // ���������� �������� ���������� ������ ��������.
  void setStart(const MyString& start);

  // ���������� �������� ��������� ������ ��������.
  void setFinish(const MyString& finish);

  // ���������� ����� ��������.
  void setNumber(int number);

  // ���������� ������� � ������� � ����.
  void toThePark();
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region ���������� �������� ���������� (����, ������� ����� �����). 
#endif
  // ���������� ��������� ������������.
  Route operator= (const Route& route2);

  // ���������� ��������� ���������.
  bool operator==(const Route& route2) const;

  // ���������� ��������� �����������.
  bool operator!=(const Route& route2) const;

  // ���������� �������� ������.
  bool operator>(const Route& route2) const;

  // ���������� �������� ������.
  bool operator<(const Route& route2) const;

  // ���������� �������� ������ ��� �����.
  bool operator>=(const Route& route2) const;

  // ���������� �������� ������ ��� �����.
  bool operator<=(const Route& route2) const;
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region ���������� ++ -- � ������.
#endif
  // ���������� ��������� ����������� ����������.
  Route operator++();
  // ���������� ��������� ������������ ����������.
  Route operator++(int notused);

  // ���������� ��������� ����������� ����������.
  Route operator--();
  // ���������� ��������� ������������ ����������.
  Route operator--(int notused);

  // ���������� ��������� <<. 
  friend std::ostream& operator<< (std::ostream& out, const Route& route);

  // ���������� ��������� >>.
  friend std::istream& operator>> (std::istream& in, Route& route);
#ifdef _MSC_VER
#pragma endregion
#endif
};

#endif