#ifndef FUNCTIONS
#define FUNCTIONS

#include <vector>
#include "Route.h"
#include "MyArray.h"
#include "MyString.h"

// Заполнить массив маршрутов из файла (MyArray массив)
void fillMyArrayByFile(MyArray<Route>& routes, const MyString& fileName);

// Вывести в поток вывода таблицу маршрутов.
void showRouteArray(const MyArray<Route>& routes, std::ostream& out);

// Получить максимальный по номеру маршрут из массива.
Route getMaxRoute(const MyArray<Route>& routes);

// Получить минимальный по номеру маршрут из массива.
Route getMinRoute(const MyArray<Route>& routes);

// Шаблон сортировки массива (мой шаблон массива).
template <typename T>
void sortMyArray(MyArray<T>& a)
{
  // Массив из 1 или 0 элементов уже отсортирован.
  if (a.getSize() <= 1)
  {
    return;
  }
  for (int i = 1; i < static_cast<int>(a.getSize()); i++) // Для каждого следующего неотсортированного элемента найдем его место.
  {
    T temp = a[i];
    int j = 0;
    for (j = i - 1; (j >= 0) && a[j] > temp; j--) // Для элементов левее первого неотсортированного, пока они больше его...
    {
      // Сдвигаем их вправо.
      a[j + 1] = a[j];
    }
    a[j + 1] = temp; // Ставим первый неотсортированный элемент на своё место.
  }
}

#ifdef _MSC_VER
#pragma region Вектор пар.
#endif
// Определить, есть ли в векторе пар элемент с ключем key. Если есть - положить его в переменную index.
bool indexOfKey(const std::vector<std::pair<MyString, int>>& pairs, const MyString& key, size_t& index);

// Сортировка вектора пар по значению.
void sortPairs(std::vector<std::pair<MyString, int>>& pairs);

// Заполнить вектор пар из массива MyArray.
void setPairs(std::vector<std::pair<MyString, int>>& pairs, const MyArray<Route>& routes);

// Вывести вектор пар в поток ввода.
void showPairs(const std::vector<std::pair<MyString, int>>& pairs, std::ostream& out);
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region Функции для строк.
#endif
// Вычисление длины строки (массив char).
size_t myStrLen(const char* string);
#ifdef _MSC_VER
#pragma endregion
#endif
#endif