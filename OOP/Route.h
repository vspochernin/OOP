#ifndef ROUTE
#define ROUTE

#include <iostream>
#include <string>

class Route
{
private:
  std::string start_; // �������� ���������� ������ ��������.
  std::string finish_; // �������� ��������� ������ ��������.
  int number_; // ����� ��������.
public:
#ifdef _MSC_VER
#pragma region ������������ � ����������.
#endif
  // ����������� ��� ����������.
  Route();

  // ����������� � �����������.
  Route(const std::string& start, const std::string& finish, int number);

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
  std::string getStart() const;

  // �������� �������� ��������� ������ ��������.
  std::string getFinish() const;

  // �������� ����� ��������.
  int getNumber() const;

  // ���������� �������� ���������� ������ ��������.
  void setStart(const std::string& start);

  // ���������� �������� ��������� ������ ��������.
  void setFinish(const std::string& finish);

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