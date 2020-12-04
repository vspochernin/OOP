#ifndef FUNCTIONS
#define FUNCTIONS

#include <vector>
#include "Route.h"
#include "MyArray.h"
#include "MyString.h"

// ��������� ������ ��������� �� ����� (MyArray ������)
void fillMyArrayByFile(MyArray<Route>& routes, const MyString& fileName);

// ������� � ����� ������ ������� ���������.
void showRouteArray(const MyArray<Route>& routes, std::ostream& out);

// �������� ������������ �� ������ ������� �� �������.
Route getMaxRoute(const MyArray<Route>& routes);

// �������� ����������� �� ������ ������� �� �������.
Route getMinRoute(const MyArray<Route>& routes);

// ������ ���������� ������� (��� ������ �������).
template <typename T>
void sortMyArray(MyArray<T>& a)
{
  // ������ �� 1 ��� 0 ��������� ��� ������������.
  if (a.getSize() <= 1)
  {
    return;
  }
  for (int i = 1; i < static_cast<int>(a.getSize()); i++) // ��� ������� ���������� ������������������ �������� ������ ��� �����.
  {
    T temp = a[i];
    int j = 0;
    for (j = i - 1; (j >= 0) && a[j] > temp; j--) // ��� ��������� ����� ������� ������������������, ���� ��� ������ ���...
    {
      // �������� �� ������.
      a[j + 1] = a[j];
    }
    a[j + 1] = temp; // ������ ������ ����������������� ������� �� ��� �����.
  }
}

#ifdef _MSC_VER
#pragma region ������ ���.
#endif
// ����������, ���� �� � ������� ��� ������� � ������ key. ���� ���� - �������� ��� � ���������� index.
bool indexOfKey(const std::vector<std::pair<MyString, int>>& pairs, const MyString& key, size_t& index);

// ���������� ������� ��� �� ��������.
void sortPairs(std::vector<std::pair<MyString, int>>& pairs);

// ��������� ������ ��� �� ������� MyArray.
void setPairs(std::vector<std::pair<MyString, int>>& pairs, const MyArray<Route>& routes);

// ������� ������ ��� � ����� �����.
void showPairs(const std::vector<std::pair<MyString, int>>& pairs, std::ostream& out);
#ifdef _MSC_VER
#pragma endregion
#endif

#ifdef _MSC_VER
#pragma region ������� ��� �����.
#endif
// ���������� ����� ������ (������ char).
size_t myStrLen(const char* string);
#ifdef _MSC_VER
#pragma endregion
#endif
#endif