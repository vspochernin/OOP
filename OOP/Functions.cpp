#include "Functions.h"
#include <fstream>
#include <iomanip>

// Заполнить массив маршрутов из файла. (Встроенный С++ массив)
void fillArrayByFile(Route routes[], size_t size, std::string fileName)
{
	std::ifstream fin(fileName);
	size_t i = 0;
	size_t nElements = 0; // По сути, эта переменная нужна только, чтобы считать в неё первую строчку файла.
	fin >> nElements;
	while (!fin.eof() && i < size)
	{
		fin >> routes[i];
		i++;
	}
	fin.close();
}

// Заполнить массив маршрутов из файла. (Динамический массив)
void fillDynArrayByFile(Route*& routes, size_t& size, std::string fileName)
{
	std::ifstream fin(fileName);
	size_t nElements = 0;
	fin >> nElements;
	size = nElements;
	routes = new Route[nElements];
	size_t i = 0;
	while (!fin.eof() && i < nElements)
	{
		fin >> routes[i];
		i++;
	}
	fin.close();
}

// Вывести в поток вывода таблицу маршрутов.
void showRouteArray(Route routes[], size_t size, std::ostream& out)
{
	out << "-----------------------------------------------" << std::endl;
	out << "|Номер маршрута|Начало маршрута|Конец маршрута|" << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		out << routes[i] << std::endl;
	}
	out << "-----------------------------------------------" << std::endl;
}

// Получить индекс максимального по номера маршрута из массива.
size_t getIndexOfMaxRoute(Route routes[], size_t size)
{
	size_t indexMax = 0;
	int maxRouteNumber = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (routes[i].getRouteNumber() > maxRouteNumber)
		{
			maxRouteNumber = routes[i].getRouteNumber();
			indexMax = i;
		}
	}
	return indexMax;
}

// Получить индекс минимального по номера маршрута из массива.
size_t getIndexOfMinRoute(Route routes[], size_t size)
{
	size_t indexMin = 0;
	int minRouteNumber = INT_MAX;
	for (size_t i = 0; i < size; i++)
	{
		if (routes[i].getRouteNumber() < minRouteNumber)
		{
			minRouteNumber = routes[i].getRouteNumber();
			indexMin = i;
		}
	}
	return indexMin;
}

#pragma region Вектор пар.
// Проверить, есть ли в векторе пар элемент с ключем key?
bool isContainsKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == key)
		{
			return true;
		}
	}

	return false;
}

// Получить индекс элемента вектора пар с ключем key (подразумевается, что пара с таким ключем в векторе есть).
size_t getIndexOfKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first == key)
		{
			return i;
		}
	}
}

// Сортировка вектора пар по значению.
void sortPairs(std::vector<std::pair<std::string, int>>& pairs)
{
	// Массив из 1 или 0 элементов уже отсортирован.
	if (pairs.size() <= 1)
	{
		return;
	}
	for (int i = 1; i < pairs.size(); i++) // Для каждого следующего неотсортированного элемента найдем его место.
	{
		std::pair<std::string, int> temp = pairs[i];
		int j = 0;
		for (j = i - 1; (j >= 0) && pairs[j].second < temp.second; j--) // Для элементов левее первого неотсортированного, пока они больше его...
		{
			// Сдвигаем их вправо.
			pairs[j + 1] = pairs[j];
		}
		pairs[j + 1] = temp; // Ставим первый неотсортированный элемент на своё место.
	}
}

// Заполнить вектор пар из массива.
void setPairs(std::vector<std::pair<std::string, int>>& pairs, Route* routes, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (isContainsKey(pairs, routes[i].getFinish()))
		{
			pairs[getIndexOfKey(pairs, routes[i].getFinish())].second++;
		}
		else
		{
			pairs.push_back(std::make_pair<std::string, int>(routes[i].getFinish(), 1));
		}
	}
}

// Вывести вектор пар в поток вывода.
void showPairs(const std::vector<std::pair<std::string, int>>& pairs, std::ostream& out)
{
	out << "-------------------------------" << std::endl;
	out << "|Конец маршрута|Число машрутов|" << std::endl;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		out << "|" << std::setw(14) << pairs[i].first << "|" << std::setw(14) << pairs[i].second << "|" << std::endl;
	}
	out << "-------------------------------" << std::endl;
}
#pragma endregion