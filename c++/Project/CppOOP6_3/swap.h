#pragma once
#include <iostream>

class Foo
{

};

template <typename T>
void swap(T& x, T& y)
{
    std::cout << "swap" << std::endl;
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
void swap(T* x, T* y) // �����Ϳ� ���� Ư��ȭ
{
    std::cout << "swap pointer" << std::endl;
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <>
void swap<Foo>(Foo& x, Foo& y) // ����� Ư��ȭ, swap ���� <> �� ����� �Ͻ��� Ư��ȭ
{
    std::cout << "swap<Foo>" << std::endl;
}

