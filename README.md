# cxx-coursework-2020
Курсовая работа по дисциплине "Основы программирования". (С++) 1-й семестр 1-го курса СПБПУ ИКНТ ПИ (2020-2021 уч. г).

## Общая постановка задачи.
1. В соответствии с выбранным вариантом задания требуется разработать класс (классы).
2. Для разрабатываемого класса необходимо выполнить:
	1) Описание полей класса.
	2) Конструктор без параметров, конструктор с параметрами
	3) Конструктор копирования, оператор присваивания, деструктор.
	4) Перегрузку бинарных операторов (всех, которые имеют смысл).
	5) Перегрузку операторов отношения.
	6) Перегрузку операторов инкремента и декремента.
	7) Перегрузку операторов << и >> через дружественные функции.
3. Создать массив из объектов разработанного класса. Ввести в массив данные из текстового
файла.
4. Написать функцию, находящую «максимальный/минимальный» объект из неупорядоченного
массива. Для сравнения использовать перегруженный оператор отношения.
5. Написать шаблон функции, выполняющей сортировку массива по возрастанию (метод сортировки указан варианте задания). Применить функцию к массиву объектов. Результат вывести в
файл в виде таблицы (с выводом заголовков столбцов).
6. Создать шаблон класса связного списка. Метод добавления должен позволить сформировать упорядоченный по заданному полю(ключу) связный список. Правило упорядочивания
и поле ключа должны быть согласованы с преподавателем. Создать связный список объектов. Вывести список в файл в виде таблицы (с выводом заголовков столбцов). Рекомендуется
использование стандартных контейнеров STL.
7. Предусмотреть генерацию и обработку исключительных ситуаций, связанных, например, с
проверкой значения полей перед инициализацией и присваиванием. Для исключений должны быть написаны отдельные классы. Требования к правилам формирования отдельных полей и к использованию библиотечных классов, а также спецификация программы должны
быть должны быть согласованы с преподавателем.
8. Программа должна быть написана в соответствии со стилем программирования: C++
Programming Style Guidelines (http://geosoft.no/development/cppstyle.html ).
9. Отчет по лабораторной работе должен содержать:
	1. Общая постановка задачи
	2. Требования
	3. Спецификация
	4. Тест план
	5. Блок-схема, псевдокод (можно не делать)
	6. Программа
	7. Итоги


## Вариант 11
1. Разработать класс «Маршрут:», содержащий информацию:
	* название начального пункта маршрута,
	* название конечного пункта маршрута,
	* номер маршрута.
п. 4. Сравнивать объекты по номеру маршрута.
п. 5. Сортировку массива выполнять методом простых вставок.
п. 6. Список названий конечных пунктов маршрутов и числа маршрутов, ведущих в них. Вывести в
	порядке убывания числа маршрутов.
