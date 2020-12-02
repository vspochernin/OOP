#ifndef FUNCTIONS
#define FUNCTIONS

#include <vector>

#include "Route.h"

// ��������� ������ ��������� �� �����. (���������� �++ ������)
void fillArrayByFile(Route routes[], size_t size, std::string fileName);

// ��������� ������ ��������� �� �����. (������������ ������)
void fillDynArrayByFile(Route*& routes, size_t& size, std::string fileName);

// ������� � ����� ������ ������� ���������.
void showRouteArray(Route routes[], size_t size, std::ostream& out);

// �������� ������ ������������� �� ������ �������� �� �������.
Route getMaxRoute(Route routes[], size_t size);

// �������� ������ ������������ �� ������ �������� �� �������.
Route getMinRoute(Route routes[], size_t size);

// ������ ���������� �������.
template <typename T>
void sortArray(T a[], int size)
{
	// ������ �� 1 ��� 0 ��������� ��� ������������.
	if (size <= 1)
	{
		return;
	}
	for (int i = 1; i < size; i++) // ��� ������� ���������� ������������������ �������� ������ ��� �����.
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

#pragma region ������ ���.
// ����������, ���� �� � ������� ��� ������� � ������ key. ���� ���� - �������� ��� � ���������� index.
bool indexOfKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key, size_t& index);

// ���������� ������� ��� �� ��������.
void sortPairs(std::vector<std::pair<std::string, int>>& pairs);

// ��������� ������ ��� �� �������.
void setPairs(std::vector<std::pair<std::string, int>>& pairs, Route* routes, size_t size);

// ������� ������ ��� � ����� ������.
void showPairs(const std::vector<std::pair<std::string, int>>& pairs, std::ostream& out);
#pragma endregion

#endif