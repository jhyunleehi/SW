#include <iostream>


constexpr int fib(int num)
{
    return num <= 1 ? num : fib(num - 2) + fib(num - 1);
}


template<int N>
void print()
{
    std::cout << N << std::endl;
}


struct Item
{
    int power;
    constexpr Item(int power) : power(power)  
    {

    }

    constexpr Item operator+(const Item& other) const
    {
        return Item(power + other.power);
    }
};


template<typename T>
auto getValue(T t)
{
    if constexpr (std::is_pointer<T>()) // ������ �ð��� �� ��
        return *t;
    else
        return t;
}

int main()
{
    constexpr int value = fib(10); // fib�� ��� �ð��� ������ ���� �ʴ´ٸ� ������ ���� �߻�.
    std::cout << value << std::endl;

    // �迭 ���� value�� ���� ������ ���� ������ �ð��� �� �Ǿ���
    int nums[value];

    // ���ø��� non type �Ķ���Ϳ� value�� ���� ������ ���� ������ �ð��� �� �Ǿ���.
    print<value>();


    // ����ð��� �� ��
    constexpr Item item0(10);
    constexpr Item item1(20);
    constexpr Item newItem = item0 + item1;

    // ����ð��� �� �Ʊ� ������ �迭 ���� ����
    int nums1[newItem.power];


    int num = 10;
    int *pNum = &num;

    std::cout << getValue(num) << std::endl;
    std::cout << getValue(pNum) << std::endl;


    auto func = [](int y) { // C++17���� ���ٿ� �Ͻ������� constexpr�� �پ� ����
        return y;
    };

    int nums0[func(10)]; // ���ٰ� ����ð��� �� ��
}