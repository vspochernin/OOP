#ifndef MY_STRING
#define MY_STRING

class MyString
{
public:
  // ����������� ��� ����������.
  MyString();

  // ����������� � ���������� (�� ������� ������).
  MyString(const char* string);

  // ����������� �����������.
  MyString(const MyString& myString);

  // ����������.
  ~MyString();

  // �������� ������.
  char* get() const;

  // ���������� ��������� =.
  MyString& operator=(const MyString& myString2);

  // ���������� ��������� +.
  MyString operator+(const MyString& myString2) const;

  // ���������� �������� ==.
  bool operator==(const MyString& myString2) const;

  // ���������� �������� !=.
  bool operator!=(const MyString& myString2) const;

  // ���������� ��������� [].
  char& operator[](size_t index);
private:
  char* string_;
  size_t size_;
};


#endif
