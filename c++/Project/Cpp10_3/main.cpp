#include <iostream>


using namespace std;


int main()
{
    {
        // �ڵ� ����, ������ ����� ������, ���Ͽ� ���� ������ �ʱ�ȭ
        int num0;

        // ���� ����, ������ ����� ������ ���� ����. ���α׷� ���� �� ����, �� �� �� �ʱ�ȭ
        static int num1;
    }
    {
        for (int i = 0; i < 10; ++i)
        {
            int num0 = 0;
            ++num0;
            cout << num0 << endl; // 1

            static int num1 = 0;
            ++num1;
            cout << num1 << endl; // ��� ����
        }
    }
    {
        // ���� ����, �̸��� ����
        int *p = new int;
        delete p; // �������� ������ ��
        
        // �ش� ������ ��� �� p ��ü�� ������ ������ p�� ����Ű�� *p�� ���� ���� �ʴ´�.
    }
}