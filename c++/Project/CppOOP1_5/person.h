#pragma once

// #pragma once -> ��������� �� ���� include �ϵ��� ��, ��ǥ��
// #ifndef #define #endif -> ��������� �� ���� include �ϵ��� ��, ǥ��
#include <iostream>
#include <string>


// Person Ŭ������ ���� �и�
class Person
{
private:
    float _weight;
    float _height;
    const std::string _name;

public:
    Person(float weight, float height, const std::string& name);
    void print();
};


// �Լ��� ����
void foo();
