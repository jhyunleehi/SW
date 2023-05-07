#include <iostream>

using namespace std;

int main()
{
    {
        // ���� ������
        // (A) ? (B) : (C)
        // A�� true�� B ���� �� ����
        // A�� false�� C ���� �� ����

        // ���밪 ���ϱ�
        int num = -10;
        int abs = num < 0 ? -num : num;


        num = 0;
        (num == 0 ? (cout << "num == 0") : (cout << "num != 0")) << endl;
        cout << (num == 0 ? "num == 0" : "num != 0") << endl;

        // 1�� "num != 0"�� ȣȯ�� �� �Ǵ� Ÿ���̶� ���� �����ڸ� ����� �� ����
        // num == 0 ? 1 : "num != 0";
    }
    {
        // sizeof ������
        int num = 0;
        cout << sizeof(num) << endl;
        cout << sizeof num << endl;
        cout << sizeof(int) << endl;
    }
    {
        // ���� ���� ������ (::)
        std::cout << 1 << std::endl;
        std::ios_base::floatfield;
    }
    {
        // �Ͻ��� ����ȯ
        unsigned int uintNum = 1;
        int intNum = 1u;
        float fNum = 1.1f;

        uintNum = intNum;
        intNum = uintNum;
        fNum = intNum;

        short sNum = numeric_limits<int>::max();
        cout << sNum << endl; // �Ͻ��� ����ȯ�� ����, ���� �÷ο�

        // ����ȯ ������
        cout << 'a' << endl;
        cout << (int)'a' << endl; // C��Ÿ�� ����ȯ
        cout << int('a') << endl; // C++ ��Ÿ�� ����ȯ

        // C++ ��Ÿ���� ����ȯ �����ڵ� (���� ��� ����)
        // static_cast
        // const_cast
        // dynamic_cast
        // reinterpret_cast
    }
}