// Почернин Владислав Сергеевич.
// Вариант 11.

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

  fout << "Изначальный массив:" << std::endl;
  showRouteArray(routes, fout);

  fout << std::endl << "Максимальный номер маршрута: " << getMaxRoute(routes).getNumber();
  fout << std::endl << "Минимальный номер маршрута: " << getMinRoute(routes).getNumber() << std::endl << std::endl;

  sortMyArray(routes);
  fout << "Массив после сортировки:" << std::endl;
  showRouteArray(routes, fout);

  std::vector<std::pair<MyString, int>> pairs;
  setPairs(pairs, routes);
  sortPairs(pairs);
  fout << std::endl << "Список названий конечных пунктов маршрутов и числа маршрутов, ведущих в них в порядке убывания числа маршрутов:" << std::endl;
  showPairs(pairs, fout);

  // TODO: Проверить на утечки.
  fout.close();

  return 0;
}