#include <windows.h>
#include <exception>

#include "Functions.h"
// TODO: Выяснить, в чем было дело? (Френд не дружился, если инклюдить в другом порядке).
#include "MyString.h"

// Конструктор без параметров.
MyString::MyString() : string_(nullptr), size_(0) {}

// Конструктор с параметром (из обычной строки).
MyString::MyString(const char* string)
{
  size_t size = myStrLen(string);
  string_ = new char[size + 1];
  size_ = size;

  for (size_t i = 0; i < size; i++)
  {
    string_[i] = string[i];
  }

  string_[size] = '\0';
}

// Консутрктор копирования.
MyString::MyString(const MyString& myString)
{
  size_t size = myString.size_;
  string_ = new char[size + 1];
  size_ = size;

  for (size_t i = 0; i < size; i++)
  {
    string_[i] = myString.string_[i];
  }

  string_[size] = '\0';
}

// Деструктор.
MyString::~MyString()
{
  delete[] string_;
}

// Получить строку.
char* MyString::get() const
{
  return string_;
}

// Перегрузка оператора =.
MyString& MyString::operator=(const MyString& myString2)
{
  if (this == &myString2)
  {
    return *this;
  }

  // Очистка памяти.
  if (string_ != nullptr)
  {
    delete[] string_;
  }

  size_ = myString2.size_;
  string_ = new char[size_ + 1];

  for (size_t i = 0; i < size_; i++)
  {
    string_[i] = myString2.string_[i];
  }

  string_[size_] = '\0';

  return *this;
}

// Перегрузка оператора +.
MyString MyString::operator+(const MyString& myString2) const
{
  size_t size1 = size_;
  size_t size2 = myString2.size_;
  size_t newSize = size1 + size2;

  MyString newString;
  newString.size_ = newSize;
  newString.string_ = new char[newSize + 1];
  size_t i = 0;
  for (size_t j = 0; j < size1; j++)
  {
    newString.string_[i] = string_[i];
    i++;
  }
  for (size_t j = 0; j < size2; j++)
  {
    // TODO: Что делать с этой ошибкой (предупреждением)?
    newString.string_[i] = myString2.string_[j];
    i++;
  }
  newString.string_[newSize] = '\0';

  return newString;
}

// Перегрузка опретора ==.
bool MyString::operator==(const MyString& myString2) const
{
  if (size_ != myString2.size_)
  {
    return false;
  }

  for (size_t i = 0; i < size_; i++)
  {
    if (string_[i] != myString2.string_[i])
    {
      return false;
    }
  }

  return true;
}

// Перегрузка опретора !=.
bool MyString::operator!=(const MyString& myString2) const
{
  if (size_ != myString2.size_)
  {
    return true;
  }

  for (size_t i = 0; i < size_; i++)
  {
    if (string_[i] != myString2.string_[i])
    {
      return true;
    }
  }

  return false;
}

// Перегрузка оператора [].
char& MyString::operator[](size_t index)
{
  if ((index < 0) || (index >= size_))
  {
    // TODO: Выяснить, правильно ли делаю.
    throw (std::out_of_range("Неккоректный индекс, выход за границы массива."));
  }

  return string_[index];
}

// Перегрузка оператора <<. 
std::ostream& operator<< (std::ostream& out, const MyString& myString)
{
  return (out << myString.string_);
}

// Перегрузка оператора >>.
// TODO: Еще раз тщательно просмотреть алгоритм.
std::istream& operator>> (std::istream& in, MyString& myString)
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  char* input = new char[256]; // Выделяем считывающей строке оверсайз памяти.
  // TODO: Уточнить, верно ли? (как считываем свою строку).
  char symbol = ' ';
  while ((!in.eof()) && ((in.peek() == ' ') || (in.peek() == '\n'))) // Пока впереди есть разделители - убираем их из потока.
  {
    symbol = in.get();
  }
  symbol = in.get(); // Будем посимвольно считывать сюда.
  size_t i = 0;
  while ((symbol != ' ') && (symbol != '\n')) // Пока мы не считали разделитель.
  {
    input[i] = symbol; // Записываем очередной символ в считывающую строку.
    if (in.eof()) // Чтобы последний символ последней строки не считывался бесконечно.
    {
      break;
    }
    symbol = in.get(); // И считываем очередной символ.
    i++;
  }
  input[i] = '\0'; // После того, как дошли до разделителя, записываем конечный ноль.

  while ((!in.eof()) && ((in.peek() == ' ') || (in.peek() == '\n'))) // Пока впереди есть разделители - убираем их из потока.  (Конец потока ввода - Ctrl+Z!!!)
  {
    symbol = in.get();
  }

  if (myString.string_ != nullptr)
  {
    delete[] myString.string_;
  }
  myString.size_ = myStrLen(input);
  myString.string_ = new char[myString.size_ + 1];
  for (size_t i = 0; i < myString.size_; i++)
  {
    myString.string_[i] = input[i];
  }
  myString.string_[myString.size_] = '\0';

  // TODO: уточнить, верно ли? (Что возвращаем).
  return in;
}