#pragma once

#include "Route.h"
#include <vector>

// Заполнить массив маршрутов из файла. (Встроенный С++ массив)
void fillArrayByFile(Route routes[], size_t size, std::string fileName);

// Заполнить массив маршрутов из файла. (Динамический массив)
void fillDynArrayByFile(Route*& routes, size_t& size, std::string fileName);

// Вывести в поток вывода таблицу маршрутов.
void showRouteArray(Route routes[], size_t size, std::ostream& out);

// Получить индекс максимального по номера маршрута из массива.
size_t getIndexOfMaxRoute(Route routes[], size_t size);

// Получить индекс минимального по номера маршрута из массива.
size_t getIndexOfMinRoute(Route routes[], size_t size);

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
// Проверить, есть ли в векторе пар элемент с ключем key?
bool isContainsKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key);

// Получить индекс элемента вектора пар с ключем key (подразумевается, что пара с таким ключем в векторе есть).
size_t getIndexOfKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key);

// Сортировка вектора пар по значению.
void sortPairs(std::vector<std::pair<std::string, int>>& pairs);

// Заполнить вектор пар из массива.
void setPairs(std::vector<std::pair<std::string, int>>& pairs, Route* routes, size_t size);

// Вывести вектор пар в поток вывода.
void showPairs(const std::vector<std::pair<std::string, int>>& pairs, std::ostream& out);
#pragma endregion