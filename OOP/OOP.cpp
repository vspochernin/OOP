// �������� ��������� ���������.
// ������� 11.

#include <iostream>
#include <fstream>
#include <vector>

#include "Route.h"
#include "Functions.h"
#include "MyExceptions.h"
#include "MyString.h"
#include "MyArray.h"
#include "ExceptionNames.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  MyString inputFileName("input.txt");
  MyString outputFileName("output.txt");
  std::ofstream fout;
  try
  {
    fout.open(outputFileName.get());
    if (!fout)
    {
      throw (outputFileName + MyString(ERROR_FILE_IS_NOT_OPEN));
    }
  }
  catch (const MyString& error)
  {
    std::cout << ERROR_WITH_FILE << error.get();
    return 1;
  }
  MyArray<Route> routes;
  try
  {
    fillMyArrayByFile(routes, inputFileName);
  }
  catch (const MyString& error)
  {
    std::cout << ERROR_WITH_FILE << error.get();
    return 1;
  }
  catch (InvalidInput& ex)
  {
    std::cout << ERROR_WITH_INPUT << ex.what();
    return 1;
  }

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

  // TODO: ��������� �� ������.
  fout.close();

  return 0;
}