#include <iostream>
#include <vector>
#include "swap.h"

using std::cout;
using std::endl;


// ���ø� Ư��ȭ
template<typename T, typename S>
class Test
{
public:
    T num0;
    S num1;
};


// ���� Ư��ȭ
template<>
class Test<int, float>
{

};


// �κ� Ư��ȭ
template<typename T>
class Test<T, T>
{

};



int main()
{
    Foo f0, f1;
    swap(f0, f1);

    int x = 10, y = 20;
    int* px = &x, * py = &y;
    swap(px, py);

    cout << x << endl;
    cout << y << endl;


    Test<int, int> t0;
    Test<int, float> t1;
    Test<float, int> t2;

    // bool�� �״�� ����ϸ� ȿ���� �������� ������ vector���� Ư��ȭ�� ����Ѵ�
    std::vector<bool> vb;
}