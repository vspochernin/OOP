// �������� ��������� ���������.
// ������� 11.
// ����� ���������� ������� ���� �� ���� ���������� - ��� ��� ��, ����� ����� �������� ��� ������ ���� (��� ���������������, �� ����� � ������������ ���� ���������).
// ����������� 1 ���������� �� ������ �����������.
// ��������� ��� ��������� ��� ����������� (����������� � �����������) � �������� (�.�. ������, ����� ������ ���� ������ ��������.
// ��������� ��� - 3 �����.
// ���������� ������� �� �����.
// ������ ��� ��� ������ - ����� ����� � ������ �������.

#include <iostream>
#include <fstream>
#include <vector>
#include "Route.h"
#include "Functions.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::ofstream fout("output.txt");

	Route* routes = nullptr;
	size_t nRoutes = 0;

	fillDynArrayByFile(routes, nRoutes, "input.txt");
	fout << "����������� ������:" << std::endl;
	showRouteArray(routes, nRoutes, fout);

	fout << std::endl << "������������ �� ������ ������� - ��� ������� �" << getIndexOfMaxRoute(routes, nRoutes) + 1 << ". ��� �����: " <<
		routes[getIndexOfMaxRoute(routes, nRoutes)].getRouteNumber();
	fout << std::endl << "����������� �� ������ ������� - ��� ������� �" << getIndexOfMinRoute(routes, nRoutes) + 1 << ". ��� �����: " <<
		routes[getIndexOfMinRoute(routes, nRoutes)].getRouteNumber() << std::endl << std::endl;

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
	return 0;
}