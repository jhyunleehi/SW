#include <iostream>

using std::cout;
using std::endl;

// �Լ� ���ø�
// �����δ� �Լ��� �ƴϴ�. �Լ��� ���� ���ø�, ���ø��� ������� ���� �Լ� �ڵ尡 ���������
// ���ø� �Ķ���ͷ� Ÿ���� �޴´�
template<typename T>
void swap(T& x, T& y)
{
    int temp = x;
    x = y;
    y = temp;
}


// ���ø��� �Ķ���ͷ� int ���� �޴´�
template<int N>
int func(int (&nums)[N])
{
    return N;
}


// Ÿ�� �Ķ���Ϳ� �� �Ķ���͸� ���� �޴� ���ø�
template<int N, typename T>
int getSize(T(&nums)[N])
{
    return N;
}

int main()
{
    {
        int x = 10, y = 20;
        swap<int>(x, y); // Ÿ�� ���
        cout << x << endl;
        cout << y << endl;

        swap(x, y); // ������� �ʾƵ� Ÿ���� �߷еȴ�.(���⼭�� int�� �߷еȴ�)
    }


    {
        int nums[] = { 1, 2, 3 };
        cout << func<3>(nums) << endl; // �� ���
        cout << func(nums) << endl;  // 3�� �߷��Ѵ�. �� �迭�� ����� �߷��� ���ؼ� ���� �� �ִ�
    }
    {
        int nums[] = { 1, 2, 3 };
        cout << getSize(nums) << endl;

        char chars[] = {'a'};
        cout << getSize(chars);
    }
}