#include <fstream>
#include <iomanip>

#include "Functions.h"

// ��������� ������ ��������� �� �����. (���������� �++ ������)
void fillArrayByFile(Route routes[], size_t size, std::string fileName)
{
  std::ifstream fin(fileName);
  size_t i = 0;
  size_t nElements = 0; // �� ����, ��� ���������� ����� ������, ����� ������� � �� ������ ������� �����.
  fin >> nElements;
  while (!fin.eof() && i < size)
  {
    fin >> routes[i];
    i++;
  }
  fin.close();
}

// ��������� ������ ��������� �� �����. (������������ ������)
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

// ������� � ����� ������ ������� ���������.
void showRouteArray(Route routes[], size_t size, std::ostream& out)
{
  out << "-----------------------------------------------" << std::endl;
  out << "|����� ��������|������ ��������|����� ��������|" << std::endl;
  for (size_t i = 0; i < size; i++)
  {
    out << routes[i] << std::endl;
  }
  out << "-----------------------------------------------" << std::endl;
}

// �������� ������ ������������� �� ������ �������� �� �������.
Route getMaxRoute(Route routes[], size_t size)
{
  Route max = routes[0];
  for (size_t i = 0; i < size; i++)
  {
    if (routes[i] > max)
    {
      max = routes[i];
    }
  }
  return max;
}

// �������� ������ ������������ �� ������ �������� �� �������.
Route getMinRoute(Route routes[], size_t size)
{
  Route min = routes[0];
  for (size_t i = 0; i < size; i++)
  {
    if (routes[i] < min)
    {
      min = routes[i];
    }
  }
  return min;
}

#ifdef _MSC_VER
#pragma region ������ ���.
#endif
// ����������, ���� �� � ������� ��� ������� � ������ key. ���� ���� - �������� ��� � ���������� index.
bool indexOfKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key, size_t& index)
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

// ���������� ������� ��� �� ��������.
void sortPairs(std::vector<std::pair<std::string, int>>& pairs)
{
  // ������ �� 1 ��� 0 ��������� ��� ������������.
  if (pairs.size() <= 1)
  {
    return;
  }
  for (int i = 1; i < static_cast<int>(pairs.size()); i++) // ��� ������� ���������� ������������������ �������� ������ ��� �����.
  {
    std::pair<std::string, int> temp = pairs[i];
    int j = 0;
    for (j = i - 1; (j >= 0) && pairs[j].second < temp.second; j--) // ��� ��������� ����� ������� ������������������, ���� ��� ������ ���...
    {
      // �������� �� ������.
      pairs[j + 1] = pairs[j];
    }
    pairs[j + 1] = temp; // ������ ������ ����������������� ������� �� ��� �����.
  }
}

// ��������� ������ ��� �� �������.
void setPairs(std::vector<std::pair<std::string, int>>& pairs, Route* routes, size_t size)
{
  size_t index = 0;
  for (size_t i = 0; i < size; i++)
  {
    if (indexOfKey(pairs, routes[i].getFinish(), index))
    {
      pairs[index].second++;
    }
    else
    {
      pairs.push_back(std::make_pair<std::string, int>(routes[i].getFinish(), 1));
    }
  }
}

// ������� ������ ��� � ����� ������.
void showPairs(const std::vector<std::pair<std::string, int>>& pairs, std::ostream& out)
{
  out << "-------------------------------" << std::endl;
  out << "|����� ��������|����� ��������|" << std::endl;
  for (size_t i = 0; i < pairs.size(); i++)
  {
    out << "|" << std::setw(14) << pairs[i].first << "|" << std::setw(14) << pairs[i].second << "|" << std::endl;
  }
  out << "-------------------------------" << std::endl;
}
#ifdef _MSC_VER
#pragma endregion
#endif