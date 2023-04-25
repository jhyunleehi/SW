#include <iostream>

using std::cout;
using std::endl;

int f() { return 20; }
int func() { return 10; }

struct Person
{
    float weight;
    float height;
};

struct Wrapper0
{
    int value;
    int getValue() const
    {
        return value;
    }
};

struct Wrapper1
{
    float value;
    float& getValue()
    {
        return value;
    }
};

template<typename T>
auto getValue(T& t) -> decltype(auto) // decltype(t.getValue())
{
    return t.getValue();
}

int main()
{
    decltype(1) num0 = 10; // decltype ������ ǥ������ Ÿ���� ������ Ÿ�Կ� �߷�

    decltype(num0) num1 = 20;
    decltype(num1)& num2 = num1;

    const decltype(num0)& num3 = 10;
    const decltype(num0)& num4 = num2;

    decltype((num0)) num5 = num0; // int&
    decltype(1 + 22.2f) num6 = 1.f;

    int nums0[] = { 1, 2, 3 };
    decltype(nums0) nums1 = { 1, 2, 3 };

    decltype(func) f; // �Լ��� ������ �Ͱ� ����, �� func�� �Լ��� ����� f �Լ��� ������ ��, int f(); �� ����
    cout << f() << endl; // 20 // ����ü�� ���ٸ� ���� �߻�

    decltype(func)& f0 = func;
    cout << f0() << endl; // 10

    decltype(func)* f1 = func;
    cout << f1() << endl; // 10

    decltype(func()) num7 = 20;  // func() �� ����Ǵ� ���� �ƴ�. ���� ��ȯ���� Ÿ�Ը� ������ �ð��� �߷� ��

    Person p;
    decltype(p.weight) weight0;
    decltype(Person::weight) weight1;


    int n0 = 10;
    auto n1 = 20;
    decltype(n0) n2 = 30;
    decltype(auto) n3 = 30; // auto�� 30�� ���ؼ� int�� �߷�

    Wrapper0 w0{ 0 };
    Wrapper1 w1{ 1 };

    getValue(w0); // ��
    getValue(w1) = 10;
}