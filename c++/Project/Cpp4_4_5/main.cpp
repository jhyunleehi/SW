#include <iostream>

using namespace std;

int main()
{
    {
        // Not ������(~)
        // 0 -> 1
        // 1 -> 0
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0000 (0)
        int num = 0;

        // 1111,1111,1111,1111,1111,1111,1111,1111 (-1)
        cout << ~num << endl;
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0000 (0)
        unsigned int num = 0;

        // 1111,1111,1111,1111,1111,1111,1111,1111 (2^32 - 1)
        cout << ~num << endl;
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0001 (1)
        unsigned int num = 1;

        // 1111,1111,1111,1111,1111,1111,1111,1110 (2^32 - 2)
        cout << ~num << endl;

        // 0000,0000,0000,0000,0000,0000,0000,0001 (1)
        cout << ~~num << endl;
    }
    {
        // AND ������(&)
        // 1 & 1 == 1
        // 1 & 0 == 0
        // 0 & 1 == 0
        // 0 & 0 == 0
    }
    {
        int num0 = 5;
        int num1 = 10;

        int result = num0 & num1;
        cout << result << endl;

        // 0000,0101 == 5 == 4 + 1 == 2^2 + 2^0
        // 0000,1010 == 10 == 8 + 2 == 2^3 + 2^1
        // 0000,0000 == 0
    }
    {
        int num0 = 5;
        int num1 = 11;

        int result = num0 & num1;
        cout << result << endl;

        // 0000,0101 == 5 == 4 + 1 == 2^2 + 2^0
        // 0000,1011 == 10 == 8 + 2 == 2^3 + 2^1 + 2^0
        // 0000,0001 == 1
    }
    {
        // AND �����ڸ� �̿��Ͽ� flag�� �����ϴ��� üũ
        uint32_t attendanceBook = 5;

        if (attendanceBook & (int)pow(2, 0))
            cout << "1st" << endl;

        if (attendanceBook & (int)pow(2, 1))
            cout << "2nd" << endl;

        if (attendanceBook & (int)pow(2, 2))
            cout << "3th" << endl;

        if (attendanceBook & ((int)pow(2, 0) + (int)pow(2, 1)))
            cout << "1 or 2" << endl;

        int flag = (int)pow(2, 0) + (int)pow(2, 2);
        if ((attendanceBook & flag) == flag)
            cout << "1 and 3" << endl;

        // 0000,0000,0000,0000,0000,0000,0000,0101 = 5

        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 AND // 1�� üũ
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 // 1�� �⼮

        // 0000,0000,0000,0000,0000,0000,0000,0010 = 1 AND // 2�� üũ
        // 0000,0000,0000,0000,0000,0000,0000,0000 = 0 // 2�� �Ἦ
    }
    {
        // OR ������(|)
        // 1 | 1 == 1
        // 1 | 0 == 1
        // 0 | 1 == 1
        // 0 | 0 == 0
    }
    {
        // OR �����ڸ� �̿��Ͽ� flag�� �߰�
        uint32_t attendanceBook = 0u;

        // ù° �� �⼮ ó��
        attendanceBook |= (int)pow(2, 0);
        cout << attendanceBook << endl;

        // �ߺ��ؼ� ���� ���� �⼮�� �ص� ������ ����.
        attendanceBook |= (int)pow(2, 0);
        cout << attendanceBook << endl;

        // 0000,0000,0000,0000,0000,0000,0000,0000 = 0
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 OR // 1�� �⼮
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1
    }
    {
        uint32_t attendanceBook = 5u;

        // ��° �� �Ἦ ó�������¼¤�° ������ ���ܰ���Ἥ�� ��óöó��
        attendanceBook &= ~((int)pow(2, 2));

        // 0000,0000,0000,0000,0000,0000,0000,0101 = 5
        // 1111,1111,1111,1111,1111,1111,1111,1011 AND
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1
    }
    {
        // XOR
        // 1 ^ 1 == 0
        // 1 ^ 0 == 1
        // 0 ^ 1 == 1
        // 0 ^ 0 == 0
    }
    {
        int num0 = 5;
        int num1 = 10;

        cout << (num0 ^ num1) << endl;

        // 0000,0101 = 5
        // 0000,1010 = 10
        // 0000,1111 = 15
    }
    {
        // XOR �� �̿��Ͽ� �⼮/�Ἦ ���
        uint32_t attendanceBook = 0u;

        attendanceBook ^= (int)pow(2, 0); // 0001
        cout << attendanceBook << endl;

        attendanceBook ^= (int)pow(2, 0); // 0001 ^ 0001 == 0000
        cout << attendanceBook << endl;

        attendanceBook ^= (int)pow(2, 0); // 0000 ^ 0001 == 0001
        cout << attendanceBook << endl;
    }
    {
        // Ȧ���� �ִ� �� �Ѱ��� ���� ���ϱ�
        int a = 1, b = 3, c = 2, d = 1, e = 2;
        cout << (a ^ b ^ c ^ d ^ e) << endl;
        cout << (a ^ d ^ c ^ e ^ b) << endl; // ��ȯ ��Ģ
    }
    {
        // << ������
        // 0000,0001
        // 0000,1000
        cout << (1 << 3) << endl;


        // << �� �� �� �� ���� 2��
        cout << (1 << 0) << endl;
        cout << (1 << 1) << endl;
        cout << (1 << 2) << endl;
        cout << (1 << 3) << endl;

        // ���� �߸�(���� �÷ο�)
        int num = 2200000000;
        num <<= 2;

        cout << num << endl;

        // pow ������ ������� �ʰ� �⼮ ó��
        int attendanceBook = 0u;
        attendanceBook |= (1 << 2);
        cout << attendanceBook << endl;
    }
    {
        // >> ������
        // ���� �߸�(��� �÷ο�)
        cout << (1 >> 1) << endl;

        
        // >> �� �� �� �� ���� ����
        cout << (16 >> 1) << endl;
        cout << (8 >> 1) << endl;
        cout << (4 >> 1) << endl;
        cout << (2 >> 1) << endl;
        cout << (1 >> 1) << endl;


        cout << (14 >> 1) << endl; // 7
        cout << (15 >> 1) << endl; // 7 �߷��� ������ ������

        cout << (14 >> 2) << endl; // 3 �߷��� ������ ������
        cout << (15 >> 2) << endl; // 3 �߷��� ������ ������
    }
}