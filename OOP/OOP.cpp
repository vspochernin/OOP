// �������� ��������� ���������.
// ������� 11.
// TODO: ��������� ������������ �����, � ��������� ��������� �������� �����
// TODO: ��� ��� ������ - ����� ����� � ������ ������� (������ 3 4 5 ������).

#include <iostream>
#include <fstream>
#include <vector>
#include "Route.h"
#include "Functions.h"
#include "MyExceptions.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::ofstream fout("output.txt");

	Route* routes = nullptr;
	size_t nRoutes = 0;

	fillDynArrayByFile(routes, nRoutes, "input.txt");
	fout << "����������� ������:" << std::endl;
	showRouteArray(routes, nRoutes, fout);

	fout << std::endl << "������������ ����� ��������: " << getMaxRoute(routes, nRoutes).getRouteNumber();
	fout << std::endl << "����������� ����� ��������: " << getMinRoute(routes, nRoutes).getRouteNumber() << std::endl << std::endl;

	sortArray(routes, nRoutes);
	fout << "������ ����� ����������:" << std::endl;
	showRouteArray(routes, nRoutes, fout);

	std::vector<std::pair<std::string, int>> pairs;
	setPairs(pairs, routes, nRoutes);
	sortPairs(pairs);
	fout << std::endl << "������ �������� �������� ������� ��������� � ����� ���������, ������� � ��� � ������� �������� ����� ���������:" << std::endl;
	showPairs(pairs, fout);

	delete[] routes;
	fout.close();

	// �������� ������ ����������.
	try
	{
		Route nullRoute = Route();

		//Route badRoute1 = Route("", "", 0); // �������� ���������� � ������������ � �����������.

		//Route badRoute2 = nullRoute; // �������� ���������� � ������������ �����������.

		//nullRoute.setRouteNumber(-13); // �������� ���������� � ��������.

		Route normRoute = Route("������", "�����", 123);
		//normRoute = nullRoute; // �������� ���������� � ��������� ������������.
	}
	catch (InvalidRoute& ex)
	{
		std::cout << "��������� ����������: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}