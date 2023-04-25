#include <iostream>
#include <functional>

template<typename T>
void foo()
{
    std::cout << typeid(T).name() << std::endl; // ���ø� Ÿ�� ���� ���, �� ���� �Լ� Ÿ���� ����ϱ� ����
}


int func(float) 
{
    return 1;
}

struct Func
{
    int operator()(float value) const
    {
        return 3;
    }

    static int func0(float value)
    {
        return 4;
    }

    int func1(float value) const
    {
        return 5;
    }
};

void funcnnn(int n1, int n2, int n3)
{
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
    std::cout << n3 << std::endl;
}


int main()
{
    foo<int(float)>(); // �Լ� Ÿ�� ���

    std::function<int(float)> f = func;
    std::cout << f(5.1f) << std::endl;

    f = [](float value) { return 2; };
    std::cout << f(5.1f) << std::endl;

    f = Func();
    std::cout << f(5.1f) << std::endl;

    f = Func::func0;
    std::cout << f(5.1f) << std::endl;

    {
        // ��� �Լ�

        // std::function �� ������� �ʴ� �Ϲ� �Լ� �����ͷ� ��� �Լ��� ����ų ��
        int(Func:: * f0)(float) const = &Func::func1;
        std::cout << (Func().*f0)(2) << std::endl;

        // ��� �Լ��� ù��° ���ڿ� �ڱ��ڽ��� �Ͻ������� �޴´�
        std::function<int(const Func&, float)> f1 = &Func::func1;
        std::cout << f1(Func(), 5.1f) << std::endl;

        std::function<int(float)> f2 = std::bind(&Func::func1, Func(), std::placeholders::_1);
        std::cout << f2(5.1f) << std::endl;

        std::function<int(const Func&)> f3 = std::bind(&Func::func1, std::placeholders::_1, 5.1f);
        std::cout << f3(Func()) << std::endl;
    }

    {
        std::cout << std::endl;
        std::bind(funcnnn, std::placeholders::_3, std::placeholders::_1, std::placeholders::_2)
            (1, 2, 3);
    }
}