#pragma once

#include <iostream>
#include <functional>

using namespace std;


void func(int num)
{
    cout << num << endl;
}

typedef float real32_0;  // float�� ��Ī real32
typedef double real64_0; // double�� ��Ī real64

typedef void (*FuncType_0)(int);


using real32_1 = float;  // float�� ��Ī real32
using real64_1 = double; // double�� ��Ī real64

using FuncType_1 = void (*)(int);


void type()
{
    // ��ų� ������ Ÿ�Կ� ���� �����ϰ� ǥ���� �� �ִ�.
    auto f0 = func;
    f0(1);

    auto& f1 = func;
    f1(2);

    function<void(int)> f2 = func;
    f2(3);

    FuncType_0 f3 = func;
    f3(4);

    FuncType_1 f4 = func;
    f4(5);
}
