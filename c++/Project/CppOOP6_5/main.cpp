#include <iostream>
#include <cstdarg>


using std::cout;
using std::endl;


// C ��Ÿ�� ��������
int sum0(int count, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}


template<typename T>
T sum1(T value) // unpack�� ������ ���ڰ� ������ ��
{
    return value;
}

// C++ ��Ÿ�� ��������
template<typename T, typename... Args>
T sum1(T value, Args... args)
{
    return value + sum1(args...); // unpack
}




int main()
{
    cout << sum0(4, 10, 20, 30, 40) << endl;
    cout << sum1(10, 20, 30, 40) << endl;
}