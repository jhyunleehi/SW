#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

class String
{
private:
    char* _chars;

public:
    String(const char* chars)
        : _chars(new char[strlen(chars) + 1])
    {
        strcpy(_chars, chars);
    }

    // ���� ����(�ߺ� �ڵ�)
    //char& operator[](int index)
    //{
    //    return _chars[index];
    //}

    //const char& operator[](int index) const
    //{
    //    return _chars[index];
    //}

    // const_cast�� �̿��Ͽ� �ߺ� ����
    char& operator[](int index)
    {
        const String& s = *this;
        const char& c = s[index];
        return const_cast<char&>(c);
    }

    const char& operator[](int index) const
    {
        return _chars[index];
    }
};


void stringFunc()
{
    String s0("abc");
    std::cout << s0[0] << std::endl;

    const String& s1 = s0;
    std::cout << s1[0] << std::endl;
}
