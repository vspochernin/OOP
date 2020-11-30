#pragma once

#include "Route.h"
#include <vector>

// ��������� ������ ��������� �� �����. (���������� �++ ������)
void fillArrayByFile(Route routes[], size_t size, std::string fileName);

// ��������� ������ ��������� �� �����. (������������ ������)
void fillDynArrayByFile(Route*& routes, size_t& size, std::string fileName);

// ������� � ����� ������ ������� ���������.
void showRouteArray(Route routes[], size_t size, std::ostream& out);

// �������� ������ ������������� �� ������ �������� �� �������.
size_t getIndexOfMaxRoute(Route routes[], size_t size);

// �������� ������ ������������ �� ������ �������� �� �������.
size_t getIndexOfMinRoute(Route routes[], size_t size);

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
// ���������, ���� �� � ������� ��� ������� � ������ key?
bool isContainsKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key);

// �������� ������ �������� ������� ��� � ������ key (���������������, ��� ���� � ����� ������ � ������� ����).
size_t getIndexOfKey(const std::vector<std::pair<std::string, int>>& pairs, const std::string& key);

// ���������� ������� ��� �� ��������.
void sortPairs(std::vector<std::pair<std::string, int>>& pairs);

// ��������� ������ ��� �� �������.
void setPairs(std::vector<std::pair<std::string, int>>& pairs, Route* routes, size_t size);

// ������� ������ ��� � ����� ������.
void showPairs(const std::vector<std::pair<std::string, int>>& pairs, std::ostream& out);
#pragma endregion