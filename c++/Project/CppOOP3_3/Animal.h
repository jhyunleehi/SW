#pragma once

#include <iostream>

class Animal
{
public:
    virtual void eat() const
    {
        std::cout << "��" << std::endl;
    }

    void walk() const
    {
        std::cout << "�ѹ�" << std::endl;
    }
};


class Cat : public Animal
{
public:
    virtual void eat() const override
    {
        std::cout << "��" << std::endl;
    }

    void walk() const
    {
        std::cout << "���" << std::endl;
    }
};

class Dog : public Animal
{
public:
    virtual void eat() const override
    {
        std::cout << "�͹�" << std::endl;
    }

    void walk() const
    {
        std::cout << "�ѹ�" << std::endl;
    }
};
