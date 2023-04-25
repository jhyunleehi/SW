#include <iostream>

using std::cout;
using std::endl;

class Parent
{
public:
    Parent() {}
    explicit Parent(int i) {}
};


enum class Type
{
    A, B, C
};


void constCastFunc(int i)
{
    const int& j = i;
    int& k0 = (int&)j; // const_cast

    // C��Ÿ�� ĳ��Ʈ���� �ǵ��� ��Ȯ�ϴ�
    int& k1 = const_cast<int&>(i);
}

int main()
{
    // C ��Ÿ�� ĳ����
    int num0 = (int)Type::A;

    // �Լ��� ��Ÿ�� ĳ����
    int num1 = int(Type::A);


    // C, �Լ��� ��Ÿƿ ĳ������ �Ʒ� �� ���� ĳ������ �����Ѵ�
    int i = 10;
    float& f = (float&)i; // reinterpret_cast

    const int& j = i;
    int& k = (int&)j; // const_cast

    i = (int)Type::A; // static_cast
    // C, �Լ��� ��Ÿ�� ĳ��Ʈ���ٴ� C++�� cast�� �������



    Parent p;

    // �Ʒ��� ������ ȣ���ΰ� ��ȯ�ΰ�?, �� �� ����
    p = Parent(10);
    p = (Parent)10;
}
