// Почернин Владислав Сергеевич.
// Вариант 11.
// TODO: Проверить правильности ввода, в частности проверить открытие файла
// TODO: Для доп баллов - класс строк и шаблон массива (вклюая 3 4 5 пункты).

#include <iostream>
#include <fstream>
#include <vector>
#include "Route.h"
#include "Functions.h"
#include "MyExceptions.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::ofstream fout("output.txt");

	Route* routes = nullptr;
	size_t nRoutes = 0;

	fillDynArrayByFile(routes, nRoutes, "input.txt");
	fout << "Изначальный массив:" << std::endl;
	showRouteArray(routes, nRoutes, fout);

	fout << std::endl << "Максимальный номер маршрута: " << getMaxRoute(routes, nRoutes).getRouteNumber();
	fout << std::endl << "Минимальный номер маршрута: " << getMinRoute(routes, nRoutes).getRouteNumber() << std::endl << std::endl;

	sortArray(routes, nRoutes);
	fout << "Массив после сортировки:" << std::endl;
	showRouteArray(routes, nRoutes, fout);

	std::vector<std::pair<std::string, int>> pairs;
	setPairs(pairs, routes, nRoutes);
	sortPairs(pairs);
	fout << std::endl << "Список названий конечных пунктов маршрутов и числа маршрутов, ведущих в них в порядке убывания числа маршрутов:" << std::endl;
	showPairs(pairs, fout);

	delete[] routes;
	fout.close();

	// Проверка работы исключений.
	try
	{
		Route nullRoute = Route();

		//Route badRoute1 = Route("", "", 0); // Проверка исключения в конструкторе с параметрами.

		//Route badRoute2 = nullRoute; // Проверка исключения в конструкторе копирования.

		//nullRoute.setRouteNumber(-13); // Проверка исключения в сеттерах.

		Route normRoute = Route("Начало", "Конец", 123);
		//normRoute = nullRoute; // Проверка исключения в операторе присваивания.
	}
	catch (InvalidRoute& ex)
	{
		std::cout << "Сработало исключение: " << ex.what() << std::endl;
		return 1;
	}

	return 0;
}