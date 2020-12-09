#ifndef MY_ARRAY
#define MY_ARRAY

#include <exception>

#include "ExceptionNames.h"

template <typename Data>
class MyArray
{
public:
  // ����������� ��� ����������.
  MyArray() : size_(0), data_(nullptr) {}

  // ����������� � �����������.
  MyArray(size_t size) : size_(size), data_(new Data[size]) {}

  // ����������� �����������.
  MyArray(const MyArray<Data>& array2);

  // ����������� ����������� � ���������.
  MyArray(MyArray<Data>&& array2) noexcept;

  // ����������.
  ~MyArray()
  {
    delete[] data_;
  }

  // �������� ������ �������.
  size_t getSize() const;

  // ������ �������� ������ � ������� (��� ���� ������ ���������).
  void reAllocate(size_t size);

  // ����� ���������� �������� � ������.
  void pushBack(const Data& object);

  // ���������� ��������� [].
  Data& operator[](size_t index) const;

  // ���������� ��������� =.
  MyArray<Data>& operator=(const MyArray<Data>& array2);

  // ���������� ��������� +.
  MyArray<Data> operator+(const MyArray<Data>& array2);

  // ���������� ��������� = � ���������.
  MyArray<Data>& operator=(MyArray<Data>&& array2) noexcept;
private:
  size_t size_;
  Data* data_;
};

// ����������� �����������.
template <typename Data>
MyArray<Data>::MyArray(const MyArray<Data>& array2)
{
  if (array2.size_ == 0)
  {
    size_ = 0;
    data_ = nullptr;
  }
  else
  {
    size_ = array2.size_;
    data_ = new Data[array2.size_];
    for (size_t i = 0; i < size_; i++)
    {
      data_[i] = array2.data_[i];
    }
  }
}

// ����������� ����������� � ���������.
template <typename Data>
MyArray<Data>::MyArray(MyArray<Data>&& array2) noexcept
{
  size_ = array2.size_;
  data_ = array2.data_;
  array2.size_ = 0;
  array2.data_ = nullptr;
}

// ���������� ��������� [].
template <typename Data>
Data& MyArray<Data>::operator[](size_t index) const
{
  if (index >= size_)
  {
    throw (std::out_of_range(ERROR_INCORRECT_INDEX_OUT_OF_RANGE));
  }

  return data_[index];
}

// �������� ������ �������.
template <typename Data>
size_t MyArray<Data>::getSize() const
{
  return size_;
}

// ������ �������� ������ � ������� (��� ���� ������ ���������).
template <typename Data>
void MyArray<Data>::reAllocate(size_t size)
{
  if (data_ != nullptr)
  {
    delete[] data_;
  }

  size_ = size;
  data_ = new Data[size];
}

// ����� ���������� �������� � ������.
template <typename Data>
void MyArray<Data>::pushBack(const Data& object)
{
  Data* newData = new Data[size_ + 1];
  for (size_t i = 0; i < size_; i++)
  {
    newData[i] = data_[i];
  }
  newData[size_] = object;

  delete[] data_;
  data_ = newData;
  size_ = size_ + 1;
}

// ���������� ��������� =.
template <typename Data>
MyArray<Data>& MyArray<Data>::operator=(const MyArray<Data>& array2)
{
  delete[] data_;
  if (array2.size_ == 0)
  {
    size_ = 0;
    data_ = nullptr;
  }
  else
  {
    size_ = array2.size_;
    data_ = new Data[array2.size_];
    for (size_t i = 0; i < array2.size_; i++)
    {
      data_[i] = array2.data_[i];
    }
  }

  return *this;
}

// ���������� ��������� +.
template <typename Data>
MyArray<Data> MyArray<Data>::operator+(const MyArray<Data>& array2)
{
  MyArray<Data> temp = MyArray<Data>(size_ + array2.size_);
  for (size_t i = 0; i < size_; i++)
  {
    temp.data_[i] = data_[i];
  }
  for (size_t i = 0; i < array2.size_; i++)
  {
    temp.data_[size_ + i] = array2.data_[i];
  }

  return temp; 
}


// ���������� ��������� = � ���������.
template <typename Data>
MyArray<Data>& MyArray<Data>::operator=(MyArray<Data>&& array2) noexcept
{
  if (this == &array2)
  {
    return *this;
  }
  delete[] data_;
  size_ = array2.size_;
  data_ = array2.data_;
  array2.size_ = 0;
  array2.data_ = nullptr;

  return *this;
}

#endif