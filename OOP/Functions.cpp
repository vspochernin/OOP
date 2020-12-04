#include <fstream>
#include <iomanip>

#include "Functions.h"

// ��������� ������ ��������� �� ����� (MyArray ������)
void fillMyArrayByFile(MyArray<Route>& routes, const MyString& fileName)
{
  std::ifstream fin(fileName.get());
  size_t nElements = 0;
  fin >> nElements;
  routes.reAllocate(nElements);
  size_t i = 0;
  while (!fin.eof() && i < nElements)
  {
    fin >> routes[i];
    i++;
  }
  fin.close();
}

// ������� � ����� ������ ������� ���������.
void showRouteArray(const MyArray<Route>& routes, std::ostream& out)
{
  out << "-----------------------------------------------" << std::endl;
  out << "|����� ��������|������ ��������|����� ��������|" << std::endl;
  for (size_t i = 0; i < routes.getSize(); i++)
  {
    out << routes[i] << std::endl;
  }
  out << "-----------------------------------------------" << std::endl;
}

// �������� ������������ �� ������ ������� �� �������.
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

// �������� ����������� �� ������ ������� �� �������.
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
#pragma region ������ ���.
#endif
// ����������, ���� �� � ������� ��� ������� � ������ key. ���� ���� - �������� ��� � ���������� index.
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

// ���������� ������� ��� �� ��������.
void sortPairs(std::vector<std::pair<MyString, int>>& pairs)
{
  // ������ �� 1 ��� 0 ��������� ��� ������������.
  if (pairs.size() <= 1)
  {
    return;
  }
  for (int i = 1; i < static_cast<int>(pairs.size()); i++) // ��� ������� ���������� ������������������ �������� ������ ��� �����.
  {
    std::pair<MyString, int> temp = pairs[i];
    int j = 0;
    for (j = i - 1; (j >= 0) && pairs[j].second < temp.second; j--) // ��� ��������� ����� ������� ������������������, ���� ��� ������ ���...
    {
      // �������� �� ������.
      pairs[j + 1] = pairs[j];
    }
    pairs[j + 1] = temp; // ������ ������ ����������������� ������� �� ��� �����.
  }
}

// ��������� ������ ��� �� ������� MyArray.
// TODO: ��������, ��� ��� �� ���, ����� ���������� routes �� �� ������, ������ ��������.
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

// ������� ������ ��� � ����� �����.
void showPairs(const std::vector<std::pair<MyString, int>>& pairs, std::ostream& out)
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

#ifdef _MSC_VER
#pragma region ������� ��� �����.
#endif
// ���������� ����� ������ (������ char).
size_t myStrLen(const char* string)
{
  size_t i = 0;
  while (string[i] != '\0')
  {
    i++;
  }
  return i;
}
#ifdef _MSC_VER
#pragma endregion
#endif