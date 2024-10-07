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

    // Перегруженные операторы
    MyString& operator+=(const MyString& b);
    MyString operator+(const MyString& b);
    MyString& operator++();   // Префиксный инкремент
    MyString operator++(int); // Постфиксный инкремент
    MyString operator+(char c);  // Добавление символа в конец строки
    friend MyString operator+(char c, MyString& obj); // Добавление символа в начало строки
    MyString operator+(int n);   // Добавление n символов в конец строки
    friend MyString operator+(int n, MyString& obj);  // Добавление n символов в конец строки

    char& operator[](int index); // Индексатор
    void operator()();           // Инициализация строки с клавиатуры

    static int GetObjectCount();
};