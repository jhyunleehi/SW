#include <iostream>
#include "Person.h"

using namespace std;

// Ŭ���� ��� ���� �ʱ�ȭ
int Person::num0 = 0;
int Person::num1 = 0;
const int Person::num2 = 0; // const �ʱ�ȭ


Person::Person()
{
    num0++;
}


void Person::print()
{
    cout << num0 << endl;
}

void Person::staticPrint()
{
    cout << num0 << endl;
    //print(); // �� ���� ��� ���� �Ұ�, �� this�� ����
}

void personFunc()
{
    Person p0;
    Person p1;

    p0.print();
    p1.print();


    // public static ��� ����
    cout << Person::num1 << endl;

    Person::staticPrint();
    p0.staticPrint();
}
