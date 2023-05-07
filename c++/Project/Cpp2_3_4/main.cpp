#include <iostream>
#include <cfloat>

using namespace std;

int main()
{
    {
        // �ε��Ҽ����� ���
        float num0 = 1.5;
        float num1 = num0 * 1.5;
        float num2 = num0 / 2;
        float num3 = num0 - 3;

        cout << "num0 " << num0 << endl; // 1.5
        cout << "num1 " << num1 << endl; // 2.25
        cout << "num2 " << num2 << endl; // 0.75
        cout << "num3 " << num3 << endl; // -1.5
    }
    
    {
        // �ε��Ҽ��� �ڷ������� ������
        float fnum = 1.0;
        double dnum = 1.0;
        long double ldnum = 1.0;

        // float�� 4����Ʈ, double�� 8����Ʈ(��κ�)
        // ȯ�濡 ���� ����� �ٸ� �� ����(Ư�� long double)
        cout << "float : " << sizeof(fnum) << endl;  // 4
        cout << "double : " << sizeof(dnum) << endl;  // 8
        cout << "long double : " << sizeof(ldnum) << endl; // 8

        // ���ͷ��� � ���̻縦 ���̴� ���� ���� ���� �ڷ����� ���� �� �ִ� 
        cout << "sizeof(1.0f) : " << sizeof(1.0f) << endl; // float
        cout << "sizeof(1.0) : " << sizeof(1.0) << endl;  // double
        cout << "sizeof(1.0L) : " << sizeof(1.0L) << endl; // long double
    }

    // ���е� ����
    cout.precision(64);

    {
        // �ε� �Ҽ����� �޸� ���� ǥ��
        unsigned int uintNum;
        float fnum = -118.625f;
        memcpy(&uintNum, &fnum, sizeof(fnum));

        cout << uintNum << endl; // 1100,0010,1110,1101,0100,0000,0000,0000 = 3270328320
        cout << fnum << endl;    // 1100,0010,1110,1101,0100,0000,0000,0000 = -118.625


        fnum = 0.231689453125f;
        memcpy(&uintNum, &fnum, sizeof(fnum));

        cout << uintNum << endl; // 0011,1110,0110,1101,0100,0000,0000,0000 = 1047347200
        cout << fnum << endl;    // 0011,1110,0110,1101,0100,0000,0000,0000 = 0.231689453125
    }
    
    {
        // �ε� �Ҽ��� �� ���� �� ������
        float num0 = 0.1f;
        float num1 = 0.02f * 5.0f;

        if (num0 == num1)
            cout << "Equal 1" << endl; // ������ �� �ȴ�.
        if (num0 == 0.1f)
            cout << "Equal 2" << endl; // ������ �ȴ�.
        if (num0 == 0.1)
            cout << "Equal 3" << endl; // ������ �� �ȴ�.
        if (num0 == 0.1L)
            cout << "Equal 4" << endl; // ������ �� �ȴ�.

        cout << num0 << endl; // ������ 0.1 �� �ƴϴ�.
        cout << num1 << endl; // ������ 0.1 �� �ƴϴ�.

        cout << "0.1f : " << 0.1f << endl;
        cout << "0.1  : " << 0.1 << endl;
        cout << "0.1L : " << 0.1L << endl;


        num0 = 1.0f;
        num1 = 0.0f;
        for (int i = 0; i < 1000; i++)
            num1 = num1 + 0.001;
        if (num0 == num1)
            cout << "Equal 0" << endl;  // �� ��
        if (fabsf(num0 - num1) <= FLT_EPSILON)
            cout << "Equal 1" << endl;  // �� ��


        num0 = 1.0f;
        num1 = 0.0f;
        for (int i = 0; i < 10; i++)
            num1 = num1 + 0.1;
        if (num0 == num1)
            cout << "Equal 2" << endl;  // �� ��
        if (fabsf(num0 - num1) <= FLT_EPSILON)
            cout << "Equal 3" << endl;  // ��
    }
    
    {
        // Epsilon ����
        unsigned int intNum0 = 0b00111111100000000000000000000000;
        float fNum0;
        memcpy(&fNum0, &intNum0, sizeof(intNum0));
        cout << fNum0 << endl; // 1.0f

        unsigned int intNum1 = 0b00111111100000000000000000000001;
        float fNum1;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));
        cout << fNum1 << endl; // 1.00000011920928955078125f, float�� ǥ���� �� �ִ� 1���� ū, ���� ���� ��

        float epsilon = fNum1 - fNum0;
        cout << epsilon << endl;
        cout << FLT_EPSILON << endl;
    }

    {
        // 1.0f���� ���� �� �ִ� ���� ���� �� ���ϱ�
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b00110100000000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // Epsilon, 1.0(2) * 10^-23(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // ���� ���� ����
    }
    {
        // 1.0f���� ���� �� �ִ� ���� ���� ������ �� ���� ���� �� �� ��
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b00110011100000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // 1.0(2) * 10^-24(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // ���� ���� ������ ����
    }

    {
        // 1.0f�� ������ �� ������ ���� �������� ��
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b01001011000000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // 1.0(2) * 10^23(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // ���� ���� ����
    }
    {
        // 1.0f�� ������ �� �������� �ʴ� ��
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b01001011100000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // 1.0(2) * 10^24(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // ���� ���� ������ ����
    }

    {
        // �ִ밪 ���ϱ�
        float fnum;
        unsigned int uintNum = 0b01111111011111111111111111111111;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << FLT_MAX << endl;
        cout << fnum << endl;
    }

    {
        // NaN ���ϱ�
        float fnum;
        unsigned int uintNum = 0b01111111111111111111111111111111;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << fnum << endl;
    }

    {
        // ���Ѵ� ���ϱ�
        float fnum;
        unsigned int uintNum = 0b01111111100000000000000000000000;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << fnum << endl;
    }

    {
        // TRUE_MIN
        float fnum;
        unsigned int uintNum = 0b00000000000000000000000000000001;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << FLT_TRUE_MIN << endl;
        cout << fnum << endl;
    }

    {
        // MIN
        float fnum;
        unsigned int uintNum = 0b00000000100000000000000000000000;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << FLT_MIN << endl;
        cout << fnum << endl;
    }
}