#include <fstream>
#include <iomanip>

#include "Functions.h"
#include "MyExceptions.h"
#include "ExceptionNames.h"

// Заполнить массив маршрутов из файла (MyArray массив)
void fillMyArrayByFile(MyArray<Route>& routes, const MyString& fileName)
{
  std::ifstream fin;
  fin.open(fileName.get());
  if (!fin)
  {
    throw (fileName + MyString(ERROR_FILE_IS_NOT_OPEN));
  }
  size_t nElements = 0;
  fin >> nElements;
  if (!fin || fin.peek() != '\n')
  {
    throw (InvalidInput(ERROR_INCORRECT_LINES_NUMBER));
  }
  if (!isCorrectFileStructure(fileName, nElements + 1))
  {
    throw (InvalidInput(ERROR_INCORRECT_FILE_STRUCTURE));
  }
  routes.reAllocate(nElements);
  size_t i = 0;
  while (!fin.eof() && i < nElements)
  {
    fin >> routes[i];
    i++;
  }
  fin.close();
}

// Вывести в поток вывода таблицу маршрутов.
void showRouteArray(const MyArray<Route>& routes, std::ostream& out)
{
  out << "-----------------------------------------------" << std::endl;
  out << "|Номер маршрута|Начало маршрута|Конец маршрута|" << std::endl;
  for (size_t i = 0; i < routes.getSize(); i++)
  {
    out << routes[i] << std::endl;
  }
  out << "-----------------------------------------------" << std::endl;
}

// Получить максимальный по номеру маршрут из массива.
Route getMaxRoute(const MyArray<Route>& routes)
{
  Route max = routes[0];
  for (size_t i = 0; i < routes.getSize(); i++)
  {
    if (routes[i] > max)
    {
      max = routes[i];
    }
  }
  return max;
}

// Получить минимальный по номеру маршрут из массива.
Route getMinRoute(const MyArray<Route>& routes)
{
  Route min = routes[0];
  for (size_t i = 0; i < routes.getSize(); i++)
  {
    if (routes[i] < min)
    {
      min = routes[i];
    }
  }
  return min;
}

#ifdef _MSC_VER
#pragma region Вектор пар.
#endif
// Определить, есть ли в векторе пар элемент с ключем key. Если есть - положить его в переменную index.
bool indexOfKey(const std::vector<std::pair<MyString, int>>& pairs, const MyString& key, size_t& index)
{
  for (size_t i = 0; i < pairs.size(); i++)
  {
    if (pairs[i].first == key)
    {
      index = i;
      return true;
    }
  }

  return false;
}

// Сортировка вектора пар по значению.
void sortPairs(std::vector<std::pair<MyString, int>>& pairs)
{
  // Массив из 1 или 0 элементов уже отсортирован.
  if (pairs.size() <= 1)
  {
    return;
  }
  for (int i = 1; i < static_cast<int>(pairs.size()); i++) // Для каждого следующего неотсортированного элемента найдем его место.
  {
    std::pair<MyString, int> temp = pairs[i];
    int j = 0;
    for (j = i - 1; (j >= 0) && pairs[j].second < temp.second; j--) // Для элементов левее первого неотсортированного, пока они больше его...
    {
      // Сдвигаем их вправо.
      pairs[j + 1] = pairs[j];
    }
    pairs[j + 1] = temp; // Ставим первый неотсортированный элемент на своё место.
  }
}

// Заполнить вектор пар из массива MyArray.
void setPairs(std::vector<std::pair<MyString, int>>& pairs, const MyArray<Route>& routes)
{
  size_t index = 0;
  for (size_t i = 0; i < routes.getSize(); i++)
  {
    if (indexOfKey(pairs, routes[i].getFinish(), index))
    {
      pairs[index].second++;
    }
    else
    {
      pairs.push_back(std::make_pair<MyString, int>(routes[i].getFinish(), 1));
    }
  }
}

// Вывести вектор пар в поток ввода.
void showPairs(const std::vector<std::pair<MyString, int>>& pairs, std::ostream& out)
{
  out << "-------------------------------" << std::endl;
  out << "|Конец маршрута|Число машрутов|" << std::endl;
  for (size_t i = 0; i < pairs.size(); i++)
  {
    out << "|" << std::setw(14) << pairs[i].first << "|" << std::setw(14) << pairs[i].second << "|" << std::endl;
  }
  out << "-------------------------------" << std::endl;
}
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region Функции для строк.
#endif
// Вычисление длины строки (массив char).
size_t myStrLen(const char* string)
{
  size_t i = 0;
  while (string[i] != '\0')
  {
    i++;
  }
  return i;
}

// Определить, корректно ли задано название начала или конца маршрута?.
bool isCorrectRouteName(const MyString& string)
{
  if (string.getSize() < 2)
  {
    return false;
  }

  int ch = static_cast<int>(string.get()[0]);
  int leftBorder = static_cast<int>('А');
  int rightBorder = static_cast<int>('Я');
  if (((ch < leftBorder) || (ch > rightBorder)))
  {
    return false;
  }

  leftBorder = static_cast<int>('а');
  rightBorder = static_cast<int>('я');
  for (size_t i = 1; i < string.getSize(); i++)
  {
    ch = static_cast<int>(string.get()[i]);
    if (((ch < leftBorder) || (ch > rightBorder)) && (ch != static_cast<int>('-')))
    {
      return false;
    }
  }

  return true;
}

// Определение количества слов в строке.
int countOfWords(const char* string)
{
  int result = 0;
  bool isWord = false; // Проверка, записывается ли сейчас слово.
  for (size_t i = 0; i < myStrLen(string); i++)
  {
    if (string[i] == ' ')
    {
      isWord = false;
      continue;
    }
    if (!isWord)
    {
      result++;
      isWord = true;
    }
  }

  return result;
}
#ifdef _MSC_VER
#pragma endregion
#endif

// Проверить, корректная ли структура файла.
bool isCorrectFileStructure(const MyString& fileName, size_t countOfLines)
{
  std::ifstream fin;
  fin.open(fileName.get());
  if (fin.eof())
  {
    return false;
  }
  char* temp = new char[256];

  fin.getline(temp, 256);
  if (fin.eof() || (countOfWords(temp) > 1))
  {
    delete[] temp;
    return false;
  }

  for (size_t i = 0; i < countOfLines - 2; i++)
  {
    fin.getline(temp, 256);
    if (fin.eof() || (countOfWords(temp) != 3))
    {
      delete[] temp;
      return false;
    }
  }

  fin.getline(temp, 256);
  if (!fin.eof() || (countOfWords(temp) != 3))
  {
    delete[] temp;
    return false;
  }

  delete[] temp;
  return true;
}