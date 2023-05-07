#include <iostream>
#include "String.h"


using std::cout;
using std::endl;


int volotileFunc()
{
    // volatile ������ Ÿ�� ����ȭ�� ���� �ʰڴ�.
    // �Ź� �޸𸮿��� �о ����ϰڴ�.
    volatile int i = 0;
    i++;
    i++;
    i++;
    return i;
}

void func(const int& i)
{
    int& j = const_cast<int&>(i); // ������� �������ش�.
    j = 10;
}

int main()
{
    int i = 0;
    func(i);

    cout << i << endl;


    const int j = 0; // ������ const�� ��� ������ �� �� �ִ�
    func(j); // ���ǵ��� ���� �ൿ

    cout << j << endl;


    stringFunc();
}