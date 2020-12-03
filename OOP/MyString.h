#ifndef MY_STRING
#define MY_STRING

class MyString
{
public:
  // Конструктор без параметров.
  MyString();

  // Конструктор с параметром (из обычной строки).
  MyString(const char* string);

  // Консутрктор копирования.
  MyString(const MyString& myString);

  // Деструктор.
  ~MyString();

  // Получить строку.
  char* get() const;

  // Перегрузка оператора =.
  MyString& operator=(const MyString& myString2);

  // Перегрузка оператора +.
  MyString operator+(const MyString& myString2) const;

  // Перегрузка опретора ==.
  bool operator==(const MyString& myString2) const;

  // Перегрузка опретора !=.
  bool operator!=(const MyString& myString2) const;

  // Перегрузка оператора [].
  char& operator[](size_t index);
private:
  char* string_;
  size_t size_;
};


#endif
