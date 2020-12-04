#ifndef MY_ARRAY
#define MY_ARRAY

#include <exception>

template <typename Data>
class MyArray
{
public:
  // ����������� ��� ����������.
  MyArray() : size_(0), data_(nullptr) {}

  // ����������� � �����������.
  MyArray(size_t size) : size_(size), data_(new Data[size]) {}

  // ����������.
  ~MyArray()
  {
    delete[] data_;
  }

  // �������� ������ �������.
  size_t getSize() const;

  // ������ �������� ������ � ������� (��� ���� ������ ���������).
  void reAllocate(size_t size);

  // ���������� ��������� [].
  Data& operator[](size_t index) const;
private:
  size_t size_;
  Data* data_;
};

// ��������� �� � �����, ������ ����������� � ��������?
template <typename Data>
Data& MyArray<Data>::operator[](size_t index) const
{
  if (index >= size_)
  {
    throw (std::out_of_range("������������ ������, ����� �� ������� �������."));
  }

  return data_[index];
}

template <typename Data>
size_t MyArray<Data>::getSize() const
{
  return size_;
}

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

#endif