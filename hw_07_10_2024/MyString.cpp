#include "MyString.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;

int MyString::objectCount = 0;

MyString::MyString() {
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

MyString::MyString(int len) {
    length = len;
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

MyString::MyString(const char* inputStr) {
    length = strlen(inputStr);
    str = new char[length + 1];
    strcpy(str, inputStr);
    objectCount++;
}

MyString::~MyString() {
    delete[] str;
    objectCount--;
}

void MyString::Input() {
    cout << "Enter string: ";
    cin.getline(str, length);
}

void MyString::Print() const {
    cout << str << endl;
}

void MyString::MyStrcpy(MyString& obj) {
    delete[] str;
    length = obj.length;
    str = new char[length + 1];
    strcpy(str, obj.str);
}

bool MyString::MyStrStr(const char* substring) {
    return strstr(str, substring) != nullptr;
}

int MyString::MyChr(char c) {
    for (int i = 0; i < length; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() const {
    return length;
}

void MyString::MyStrCat(MyString& b) {
    int newLength = length + b.length;
    char* newStr = new char[newLength + 1];
    strcpy(newStr, str);
    strcat(newStr, b.str);
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MyDelChr(char c) {
    char* newStr = new char[length + 1];
    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != c) {
            newStr[j++] = str[i];
        }
    }
    newStr[j] = '\0';
    delete[] str;
    str = newStr;
    length = j;
}

int MyString::MyStrCmp(MyString& b) {
    int result = strcmp(str, b.str);
    if (result < 0) {
        return -1;
    }
    else if (result > 0) {
        return 1;
    }
    return 0;
}

// ������������� �������� += ��� ����������� �����
MyString& MyString::operator+=(const MyString& b) {
    MyStrCat(const_cast<MyString&>(b));
    return *this;
}

// ������������� �������� + ��� ����������� �����
MyString MyString::operator+(const MyString& b) {
    MyString temp;
    temp.MyStrCat(const_cast<MyString&>(b));
    return temp;
}

// ���������� ���������: ��������� ������ � ������
MyString& MyString::operator++() {
    char* newStr = new char[length + 2];
    strcpy(newStr + 1, str);
    newStr[0] = ' ';
    delete[] str;
    str = newStr;
    length++;
    return *this;
}

// ����������� ���������: ��������� ������ � �����
MyString MyString::operator++(int) {
    MyString temp(*this);
    char* newStr = new char[length + 2];
    strcpy(newStr, str);
    newStr[length] = ' ';
    newStr[length + 1] = '\0';
    delete[] str;
    str = newStr;
    length++;
    return temp;
}

// ������������� �������� [] ��� ������� � �������� �� �������
char& MyString::operator[](int index) {
    if (index >= 0 && index < length) {
        return str[index];
    }
    else {
        throw out_of_range("Index out of range");
    }
}

// ������������� �������� () ��� ������������� � ����������
void MyString::operator()() {
    cout << "Enter string: ";
    cin.getline(str, length);
}

// ������������� �������� + ��� ���������� ������� � ����� ������
MyString MyString::operator+(char c) {
    MyString temp;
    temp.length = length + 1;
    temp.str = new char[temp.length + 1];
    strcpy(temp.str, str);
    temp.str[length] = c;
    temp.str[temp.length] = '\0';
    return temp;
}

// ������������� �������� + ��� ���������� ������� � ������ ������
MyString operator+(char c, MyString& obj) {
    MyString temp;
    temp.length = obj.length + 1;
    temp.str = new char[temp.length + 1];
    temp.str[0] = c;
    strcpy(temp.str + 1, obj.str);
    return temp;
}

// ������������� �������� + ��� ���������� n �������� � ����� ������
MyString MyString::operator+(int n) {
    MyString temp;
    temp.length = length + n;
    temp.str = new char[temp.length + 1];
    strcpy(temp.str, str);
    for (int i = length; i < temp.length; i++) {
        temp.str[i] = ' ';
    }
    temp.str[temp.length] = '\0';
    return temp;
}

// ������������� �������� + ��� ���������� n �������� � ������ ������
MyString operator+(int n, MyString& obj) {
    return obj + n;
}

// ��������� ���������� ��������
int MyString::GetObjectCount() {
    return objectCount;
}
