// Почернин Владислав Сергеевич.
// Вариант 11.
// TODO: Проверить правильности ввода, в частности проверить открытие файла
// TODO: Для доп баллов - класс строк и шаблон массива (вклюая 3 4 5 пункты).
// TODO: 80 column rule
// TODO: Проверить на утечки памяти!
// TODO: Проверка на удачное открытие файла.

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
  std::ofstream fout;
  try
  {
    fout.open(outputFileName.get());
    if (!fout)
    {
      throw (outputFileName + MyString("Не открыт"));
    }
  }
  catch (const MyString& error)
  {
    std::cout << "Ошибка файла: " << error.get();
    return 1;
  }
  MyArray<Route> routes;
  try
  {
    fillMyArrayByFile(routes, inputFileName);
  }
  catch (const MyString& error)
  {
    std::cout << "Ошибка файла: " << error.get();
    return 1;
  }
  catch (InvalidInput& ex)
  {
    std::cout << "Ошибка ввода: " << ex.what();
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

  // TODO: Нужно ли вручную удалять все массивы? (И ведь в парах остается память...?)
  //routes.~MyArray();
  fout.close();

  return 0;
}