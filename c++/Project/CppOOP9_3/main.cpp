#include <iostream>
#include <functional>

void foo(std::function<void(void)> func)
{

}

void goo(int)
{

}

struct Func // ��� ���ٴ� �Լ���ü
{
    int value;
    void operator()() const // mutable �� �Լ� ��ü ���� ��
    {

    }
};

struct Test
{
    int num = 10;
    auto func()
    {
        return [num = num] { // ĸ���ϴ� ��ġ���� �ʱ�ȭ
            return num;
        };
    }
};

int main()
{
    // �⺻���� lambda�� ����
    [/*ĸ��*/](/*�Ķ����*/) /*��ȯ��*/
    {
    };

    int value = 10;
    // foo(goo); �Ѱ��� �� ����
    foo([value]() // ĸ���ؼ� �Ѱ��� �� ����
        {
            goo(value);
        });
    foo([&value]() // ������ ĸ��
        {
            goo(value);
        });

    foo([value]() mutable // �Լ���ü���� const�� ����
        {
            value = 20;
            goo(value);
        });

    Func func;
    func.value = value;
    foo(func); // ������ ����� �̰Ͱ� ������


    int num = 10;
    auto func0 = [num]() mutable
    {
        ++num;
        return num;
    };
    // �Ϲ������� �Լ� ȣ�� �� ������ ���� ���ϰ� �Ǹ� �ǵ����� ���� ��Ȳ�� �߻��� �� �ִ�. ������ �⺻������ mutable�� �ƴ�
    std::cout << func0() << std::endl; // 11
    std::cout << func0() << std::endl; // 12


    int num0 = 10;
    int num1 = 20;

    [=]() // ��� �༮�� ������ ĸ�� ����
    {
    };

    [&]() // ��� ������ ������ ĸ�� ����
    {
    };


    void (*f)(int) = [](int) {};  // ĸ�� ���� ���ٴ� �Լ� �����Ϳ� ȣȯ ��

    auto f0 = [](int) {};  // ���� �� auto ���
    std::function<void(int)> f1 = [](int) {}; // ���� �� std::function ���

    auto f2 = [](auto value) // Generic ����
    {
        return value;
    };

    auto f3 = []<typename T>(T value) // ���ø� ����, C++20
    {
        return value;
    };

}