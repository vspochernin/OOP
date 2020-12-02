#ifndef ROUTE
#define ROUTE

#include <iostream>
#include <string>

class Route
{
private:
  std::string start_; // �������� ���������� ������ ��������.
  std::string finish_; // �������� ��������� ������ ��������.
  int routeNumber_; // ����� ��������.
public:
#pragma region ������������ � ����������.
  // ����������� ��� ����������.
  Route();

  // ����������� � �����������.
  Route(const std::string& start, const std::string& finish, int routeNumber);

  // ����������� �����������.
  Route(const Route& route);

  // ����������.
  ~Route();
#pragma endregion

#pragma region ������� � �������.
  // �������� �������� ���������� ������ ��������.
  std::string getStart() const;

  // �������� �������� ��������� ������ ��������.
  std::string getFinish() const;

  // �������� ����� ��������.
  int getRouteNumber() const;

  // ���������� �������� ���������� ������ ��������.
  void setStart(const std::string& start);

  // ���������� �������� ��������� ������ ��������.
  void setFinish(const std::string& finish);

  // ���������� ����� ��������.
  void setRouteNumber(int routeNumber);

  // ���������� ������� � ������� � ����.
  void toThePark();
#pragma endregion

#pragma region ���������� �������� ���������� (����, ������� ����� �����). 
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
#pragma endregion

#pragma region ���������� ++ -- � ������.
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
#pragma endregion
};

#endif