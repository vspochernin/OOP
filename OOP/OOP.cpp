// �������� ��������� ���������.
// ������� 11.
// TODO: ��������� ������������ �����, � ��������� ��������� �������� �����
// TODO: ��� ��� ������ - ����� ����� � ������ ������� (������ 3 4 5 ������).
// TODO: 80 column rule
// TODO: ��������� �� ������ ������!

#include <iostream>
#include <fstream>
#include <vector>

#include "Route.h"
#include "Functions.h"
#include "MyExceptions.h"
#include "MyString.h"
#include "MyArray.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  MyString inputFileName("input.txt");
  MyString outputFileName("output.txt");
  std::ofstream fout(outputFileName.get());

  MyArray<Route> routes;
  fillMyArrayByFile(routes, inputFileName);
  fout << "����������� ������:" << std::endl;
  showRouteArray(routes, fout);

  fout << std::endl << "������������ ����� ��������: " << getMaxRoute(routes).getNumber();
  fout << std::endl << "����������� ����� ��������: " << getMinRoute(routes).getNumber() << std::endl << std::endl;

  sortMyArray(routes);
  fout << "������ ����� ����������:" << std::endl;
  showRouteArray(routes, fout);

  std::vector<std::pair<MyString, int>> pairs;
  setPairs(pairs, routes);
  sortPairs(pairs);
  fout << std::endl << "������ �������� �������� ������� ��������� � ����� ���������, ������� � ��� � ������� �������� ����� ���������:" << std::endl;
  showPairs(pairs, fout);

  // TODO: ����� �� ������� ������� ��� �������? (� ���� � ����� �������� ������...?)
  //routes.~MyArray();
  fout.close();

  return 0;
}