#include <iostream>
#include "case1.h"
#include "case2.h"
#include "case3.h"

using namespace std;


// ���߻���� ���� �ʿ����� ������ ������� ����
int main()
{
    case1::Derived d1;

    // � �θ��� ���� ȣ���ؾ����� ��ȣ�ϴ�
    //d.foo();
    //d.m;

    d1.BaseA::foo();
    d1.BaseA::m;
    d1.BaseB::foo();
    d1.BaseB::m;

    cout << endl;
    case2::Derived d2; // Base ������ �� �� ȣ��

    // BaseA �θ��� m���� BaseB �θ��� m���� ��ȣ�ϴ�
    //d1.m = 10;

    cout << d2.BaseA::m << endl;
    cout << d2.BaseB::m << endl;


    cout << endl;
    case3::Derived d3;

    // Base�� �� ���� ��������� ������ ��ȣ���� �ʴ�
    cout << d3.m << endl;
}