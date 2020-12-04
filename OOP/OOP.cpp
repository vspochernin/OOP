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

int main()
{
  // �������� ��������� (������ �� ����� ������������ �����).
  #if 0
  setlocale(LC_ALL, "Russian");
  std::ofstream fout("output.txt");

  Route* routes = nullptr;
  size_t nRoutes = 0;

  fillDynArrayByFile(routes, nRoutes, "input.txt");
  fout << "����������� ������:" << std::endl;
  showRouteArray(routes, nRoutes, fout);

  fout << std::endl << "������������ ����� ��������: " << getMaxRoute(routes, nRoutes).getNumber();
  fout << std::endl << "����������� ����� ��������: " << getMinRoute(routes, nRoutes).getNumber() << std::endl << std::endl;

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

    //nullRoute.setNumber(-13); // �������� ���������� � ��������.

    Route normRoute = Route("������", "�����", 123);
    //normRoute = nullRoute; // �������� ���������� � ��������� ������������.
  }
  catch (InvalidRoute& ex)
  {
    std::cout << "��������� ����������: " << ex.what() << std::endl;
    return 1;
  }
  #endif

  // ������������ ������ MyString.
  #if 1 
  setlocale(LC_ALL, "Russian");
  MyString str1 = "Helo";
  MyString str2 = "World";
  MyString str3 = str2;

  std::cout << str1.get() << std::endl;
  std::cout << str2.get() << std::endl;
  std::cout << (str1+str2).get() << std::endl;
  MyString str4;
  str4 = str1 + str2;
  char ch1 = str1[0];
  bool b1 = str1 == str2;
  bool b2 = str1 != str2;
  bool b3 = str2 == str3;
  char ch2 = str2[3];

  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;

  std::cout << std::endl << std::endl << std::endl;
  MyString str5, str6, str7, str8;
  std::cin >> str5 >> str6 >> str7 >> str8;
  std::cout << "��������� ������1: \"" << str5 << "\"." << std::endl;
  std::cout << "��������� ������1: \"" << str6 << "\"." << std::endl;
  std::cout << "��������� ������1: \"" << str7 << "\"." << std::endl;
  std::cout << "��������� ������1: \"" << str8 << "\"." << std::endl;
  #endif

  return 0;
}