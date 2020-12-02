#ifndef FUNCTIONS
#define FUNCTIONS

#include <vector>

#include "Route.h"

// Заполнить массив маршрутов из файла. (Встроенный С++ массив)
void fillArrayByFile(Route routes[], size_t size, std::string fileName);

// Заполнить массив маршрутов из файла. (Динамический массив)
void fillDynArrayByFile(Route*& routes, size_t& size, std::string fileName);

// Вывести в поток вывода таблицу маршрутов.
void showRouteArray(Route routes[], size_t size, std::ostream& out);

// Получить индекс максимального по номера маршрута из массива.
Route getMaxRoute(Route routes[], size_t size);

// Получить индекс минимального по номера маршрута из массива.
Route getMinRoute(Route routes[], size_t size);

// Шаблон сортировки массива.
template <typename T>
void sortArray(T a[], int size)
{
	// Массив из 1 или 0 элементов уже отсортирован.
	if (size <= 1)
	{
		return;
	}
	for (int i = 1; i < size; i++) // Для каждого следующего неотсортированного элемента найдем его место.
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

#pragma region Вектор пар.
// Определить, есть ли в векторе пар элемент с ключем key. Если есть - положить его в переменную index.
bool indexOfKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key, size_t& index);

// Сортировка вектора пар по значению.
void sortPairs(std::vector<std::pair<std::string, int>>& pairs);

// Заполнить вектор пар из массива.
void setPairs(std::vector<std::pair<std::string, int>>& pairs, Route* routes, size_t size);

// Вывести вектор пар в поток вывода.
void showPairs(const std::vector<std::pair<std::string, int>>& pairs, std::ostream& out);
#pragma endregion

#endif