#pragma once
class MyString
{
    char* str;
    int length;
    static int objectCount;

public:
    MyString();
    MyString(int len);
    MyString(const char* inputStr);
    ~MyString();

    void Input();
    void Print() const;

    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* substring);
    int MyChr(char c);
    int MyStrLen() const;
    void MyStrCat(MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);

    // ������������� ���������
    MyString& operator+=(const MyString& b);
    MyString operator+(const MyString& b);
    MyString& operator++();   // ���������� ���������
    MyString operator++(int); // ����������� ���������
    MyString operator+(char c);  // ���������� ������� � ����� ������
    friend MyString operator+(char c, MyString& obj); // ���������� ������� � ������ ������
    MyString operator+(int n);   // ���������� n �������� � ����� ������
    friend MyString operator+(int n, MyString& obj);  // ���������� n �������� � ����� ������

    char& operator[](int index); // ����������
    void operator()();           // ������������� ������ � ����������

    static int GetObjectCount();
};