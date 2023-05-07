#include <iostream>
#include <type_traits>

using std::cout;
using std::endl;


template<typename T>
struct is_pointer
{
    static const bool value = false;
};

template<typename T>
struct is_pointer<T*>
{
    static const bool value = true;
};

template<typename T>
void foo(T t)
{
    cout << is_pointer<T>::value << endl;
}


template<typename T>
struct remove_pointer
{
    using type = T;
};

template<typename T>
struct remove_pointer<T*>
{
    using type = T;
};

template<typename T>
struct add_pointer
{
    using type = T*;
};

template<typename T>
struct add_pointer<T&>
{
    using type = T*;
};

int main()
{
    cout << std::boolalpha;
    {
        // ������ Ÿ���� Ÿ�Կ� ���õ� ����� ����
        cout << std::is_pointer<int*>::value << endl;
        cout << std::is_pointer<int>::value << endl;


        cout << is_pointer<int*>::value << endl;
        cout << is_pointer<int>::value << endl; // ���ø� Ư��ȭ�� ���� true


        int num = 0;
        int* pNum = &num;

        foo(num);
        foo(pNum);
    }
    {
        int num = 0;
        std::add_pointer<int>::type pNum = &num;
        foo(pNum); // true 

        std::remove_pointer<int*>::type n = *pNum;
        foo(n); // false

        cout << is_pointer<remove_pointer<int*>>::value << endl; // false
    }
    {
        add_pointer<int>::type num0;
        cout << typeid(num0).name() << endl;

        add_pointer<int*>::type num1;
        cout << typeid(num1).name() << endl;

        add_pointer<int&>::type num2; // Ư��ȭ
        cout << typeid(num2).name() << endl;
    }
}