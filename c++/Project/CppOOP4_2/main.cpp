#include <iostream>

using namespace std;


class ClassA {};
class ClassB {};

enum class TypeA
{
    A, B, C
};


enum class TypeB
{
    A, B, C
};


class Test
{
public:
    Test(int num) {}
    explicit Test(int num0, int num1) {}

    operator bool() const
    {
        return true;
    }

    explicit operator double() const
    {
        return 1.2;
    }
};


class Parent {};
class Child : public Parent {};


int main()
{
    // static_cast
    // ������ Ÿ�� ��ȯ
    // ������ Ÿ�ӿ� ȣȯ ���� �ʴ� ��ȯ�� ������ ��

    float f = 1.1f;
    int* i0 = (int*)&f; // �Ϲ� C ��Ÿ�� ĳ��Ʈ�� �ȴ�
    //int* i1 = static_cast<int*>(&f); // �� �ȴ�.

    ClassA a;
    ClassB* b = (ClassB*)&a; // �Ϲ� C ��Ÿ�� ĳ��Ʈ�� �ȴ�.
    //ClassB* b = static_cast<ClassB*>(&a);  // �� �ȴ�. ������ Ÿ�ӿ� ������ ����ش�

    TypeA type0 = static_cast<TypeA>(0); // enum�� �������� ȣȯ�� �Ǳ� ������ static_cast�� �ȴ�
    TypeB type1 = static_cast<TypeB>(type0); // enum ���� ��ȯ�� ����

    Test t0 = static_cast<Test>(1); // ��ȯ ������
    Test t1 = static_cast<Test>(1, 2); // ��ȯ ������

    bool b0 = static_cast<bool>(t0);
    double d0 = static_cast<double>(t1);


    Child c;
    Parent& p0 = c;
    Child& c0 = static_cast<Child&>(p0); // Downcasting -> �θ� �ڽ����� ��ȯ
    // �׷����� �θ� �ڽ����� ĳ�����ϴ� ���� ������ �� ����

    Parent p1;
    Child& c1 = static_cast<Child&>(p1); // �� ���� ���ǵ��� ���� ����, Pointer�� ���� dynamic_cast Ȱ��


}