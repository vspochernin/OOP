#ifndef MY_ARRAY
#define MY_ARRAY

#include <exception>

template <typename Data>
class MyArray
{
public:
  // Конструктор без параметров.
  MyArray() : size_(0), data_(nullptr) {}

  // Конструктор с параметрами.
  MyArray(size_t size) : size_(size), data_(new Data[size]) {}

  // Деструктор.
  ~MyArray()
  {
    delete[] data_;
  }

  // Получить размер массива.
  size_t getSize() const;

  // Заново выделить память у массива (при этом данные пропадают).
  void reAllocate(size_t size);

  // Перегрузка оператора [].
  Data& operator[](size_t index) const;
private:
  size_t size_;
  Data* data_;
};

// Правильно ли я делаю, вынося определения в шаблонах?
template <typename Data>
Data& MyArray<Data>::operator[](size_t index) const
{
  if (index >= size_)
  {
    throw (std::out_of_range("Неккоректный индекс, выход за границы массива."));
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