#include <iostream>
#include <numeric> // �ִ밪, �ּҰ��� ���� ���� ����

// std ���� �����̽��� ������� �ʾƵ� ����� �� �ֵ��� �ϱ� ����
using namespace std;

int main()
{
    {
        // x�� �������� ������� ����
        int x;
        x = 0;

        // std::endl �� ������ �ǹ��Ѵ�.
        cout << x << endl;
    }
    {
        // ����� ���ÿ� �ʱ�ȭ
        // C ��Ÿ�� �ʱ�ȭ
        int y = 1;
        cout << y;

        // C++ ��Ÿ�� �ʱ�ȭ
        int z(2);
        cout << z << endl;
        // ����(std::endl)�� ���� y,z ���� ���޾Ƽ� ��� ��
    }
    {
        // �������� �Ҽ��� ����
        int num0 = 1;
        int num1 = num0 * 1.5;
        int num2 = num0 / 2;
        int num3 = 2.5;

        cout << "num0 " << num0 << endl; // 1
        cout << "num1 " << num1 << endl; // 1, 1.5������ �Ҽ����� ����
        cout << "num2 " << num2 << endl; // 0, 0.5������ �Ҽ����� ����
        cout << "num3 " << num3 << endl; // 2, 2.5������ �Ҽ����� ����
    }

    {
        // ������ ���ͷ�
        int num0 = 11;   // �Ϲ� ���� ���ͷ�
        int num1 = 011;  // 8���� ���� ���ͷ�
        int num2 = 0b11; // 2���� ���� ���ͷ�
        int num3 = 0x11; // 16���� ���� ���ͷ�

        cout << "num0 " << num0 << endl; // 11
        cout << "num1 " << num1 << endl; // 8 + 1 = 9
        cout << "num2 " << num2 << endl; // 2 + 1 = 3
        cout << "num3 " << num3 << endl; // 16 + 1 = 17
    }
    
    {
        // �ڷ����� ������ ���
        // Windows x86(32bit)�� ��� 4/4/4
        // Windows x64(64bit)�� ��� 4/4/8
        // Unix and Unix-like ȯ���� �ٸ� ��� ���
        int intNum = 0;
        long longNum = 0;
        int* intPointer = &intNum;

        cout << sizeof(intNum) << endl;
        cout << sizeof(longNum) << endl;
        cout << sizeof(intPointer) << endl;
    }
    {
        // ������ ������
        // ��� ȯ�濡���� ������ ���̸� �����Ѵ�.
        int8_t num00 = 0;
        int16_t num11 = 0;
        int32_t num22 = 0;

        cout << sizeof(num00) << endl; // 1
        cout << sizeof(num11) << endl; // 2
        cout << sizeof(num22) << endl; // 4
    }
    {
        // ���ͷ� ���̻縦 �̿��Ͽ� �������� ���� Ÿ���� ǥ��
        int intNum_ = 11;
        unsigned int uintNum = 11u;
        long int longNum_ = 0L;
        long long longLongNum = 0LL;
        unsigned long long ulongLongNum = 0uLL;
    }
    {
        // unsigned�� �ִ밪
        // char ���̱� ������ cout�� ���ڷ� ����� ���� �ʾ� (int)�� ����ȯ
        cout << (int)numeric_limits<uint8_t>::max() << endl;
        cout << numeric_limits<uint16_t>::max() << endl;
        cout << numeric_limits<uint32_t>::max() << endl;
        cout << numeric_limits<uint64_t>::max() << endl;
    }
    {
        // signed�� �ִ밪
        cout << (int)numeric_limits<int8_t>::max() << endl;
        cout << numeric_limits<int16_t>::max() << endl;
        cout << numeric_limits<int32_t>::max() << endl;
        cout << numeric_limits<int64_t>::max() << endl;
    }
    {
        // signed�� �ּҰ�
        cout << (int)numeric_limits<int8_t>::min() << endl;
        cout << numeric_limits<int16_t>::min() << endl;
        cout << numeric_limits<int32_t>::min() << endl;
        cout << numeric_limits<int64_t>::min() << endl;
    }
    {
        // unsigned overflow
        uint32_t unum32 = numeric_limits<uint32_t>::max();
        uint32_t unum32_ = unum32 + 1; // Overflow

        cout << unum32 << endl;  // 4294967295
        cout << unum32_ << endl; // 0, Overflow
    }
    {
        // signed overflow
        int32_t num32 = numeric_limits<int32_t>::max();
        int32_t num32_ = num32 + 1; // Overflow

        cout << num32 << endl;  // 2147483647
        cout << num32_ << endl; // -2147483648, Overflow
    }
    {
        // unsigned underflow
        uint32_t unum32 = numeric_limits<uint32_t>::min();
        uint32_t unum32_ = unum32 - 1; // Underflow

        cout << unum32 << endl;  // 0
        cout << unum32_ << endl; // 4294967295, Underflow 
    }
    {
        // signed underflow
        int32_t num32 = numeric_limits<int32_t>::min();
        int32_t num32_ = num32 - 1; // Underflow

        cout << num32 << endl;  // -2147483648
        cout << num32_ << endl; // 2147483647, Underflow
    }
}