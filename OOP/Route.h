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
	Route(const Route& r);

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
	Route operator= (const Route& r2);

	// ���������� ��������� ���������.
	bool operator==(const Route& r2) const;

	// ���������� ��������� �����������.
	bool operator!=(const Route& r2) const;

	// ���������� �������� ������.
	bool operator>(const Route& r2) const;

	// ���������� �������� ������.
	bool operator<(const Route& r2) const;

	// ���������� �������� ������ ��� �����.
	bool operator>=(const Route& r2) const;

	// ���������� �������� ������ ��� �����.
	bool operator<=(const Route& r2) const;
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
	friend std::ostream& operator<< (std::ostream& out, const Route& r);

	// ���������� ��������� >>.
	friend std::istream& operator>> (std::istream& in, Route& r);
#pragma endregion
};

#endif