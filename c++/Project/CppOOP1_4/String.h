#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <cstring>

using namespace std;


class String
{
private:
    char* _str;

public:
    String(const char* str)
    {
        int len = strlen(str);
        _str = new char[len + 1]; // '\0;
        strcpy(_str, str);
    }

    ~String()
    {
        delete[] _str; // �ı��ڿ��� ������ ������Ѵ�
    }

    void print()
    {
        cout << _str << endl;
    }
};


void stringFunc()
{
    String str("abc");
    str.print();
}
