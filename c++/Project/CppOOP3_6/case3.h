#pragma once

#include <iostream>


namespace case3
{
    class Base
    {
    public:
        int m = 10;
        Base(int m) : m(m)
        {
            std::cout << "Base(" << m << ")" << std::endl;
        }
    };

    class BaseA : virtual public Base // virtual�� �Ἥ Base�� �� ���� �����
    {
    public:
        BaseA() : Base(10)
        {
            std::cout << "BaseA" << std::endl;
        }
    };

    class BaseB : virtual public Base // virtual�� �Ἥ Base�� �� ���� �����
    {
    public:
        BaseB() : Base(20)
        {
            std::cout << "BaseB" << std::endl;
        }
    };


    class Derived : public BaseA, public BaseB
    {
    public:
        Derived()
            : Base(30) // Base�� virtual ����� �Ѵٸ� Base�� � �����ڸ� ȣ������ ��������� �Ѵ�
        {
            std::cout << "Derived" << std::endl;
        }
    };
}
