#include <iostream>
#include <type_traits>


void goo(int&& value)
{
    std::cout << "goo(int&&)" << std::endl;
}

void goo(int& value)
{
    std::cout << "goo(int&)" << std::endl;
}

void foo(int&& value) // r-value reference �� l-value
{
    goo(std::move(value)); // std::move�� �̿��� void goo(int&&)�� �Ѱ�����
}

void lref(int&) {}
void rref(int&&) {}

template<typename T>
void uref(T&& t) {}


template<typename T>
void func(T&& t)
{
    // Reference collapsing
    // && + & -> &
    // & + && -> &
    // && + && -> &&

    std::cout << "lvalue ref T : " << std::is_lvalue_reference_v<T> << std::endl;
    std::cout << "rvalue ref T : " << std::is_rvalue_reference_v<T> << std::endl;

    std::cout << "lvalue ref T& : " << std::is_lvalue_reference_v<T&> << std::endl;
    std::cout << "rvalue ref T& : " << std::is_rvalue_reference_v<T&> << std::endl;

    std::cout << "lvalue ref T&& : " << std::is_lvalue_reference_v<T&&> << std::endl;
    std::cout << "rvalue ref T&& : " << std::is_rvalue_reference_v<T&&> << std::endl;
}

template<typename T>
void func0(T&& value)
{
    func1(std::forward(value)); // �Ϻ� ����
}

void func1(int&& value)
{

}

void func1(int& value)
{

}

int main()
{
    std::move(10);

    int num = 10;
    std::move(num);

    // �� �� std::move �� ���� �Լ�.
    // ���������� T&& �� ���� �������� ����(���� ����)
    // ���ø� Ÿ�� �Ķ����, auto�� ���� Ÿ�� �߷��� �߻��ϴ� ���� &&�� ������ ���� ����


    //lref(10); // �� ��
    lref(num);

    rref(10);
    //rref(num); // �� ��
    
    uref(10);
    uref(num);

    func(num);
    std::cout << std::endl;

    int& num0 = num;
    func(num0);
    std::cout << std::endl;

    func(10);
    std::cout << std::endl;
}