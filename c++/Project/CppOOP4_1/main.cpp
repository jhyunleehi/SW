#include <iostream>


using namespace std;


void func(float f)
{

}


int main()
{
    // double�� float���� �� ��ȯ
    float f = 1;

    // double�� float���� �� ��ȯ
    func(1);

    char ch0 = 'a';
    int num0 = ch0; // promotion, widening conversion, Ȯ�� ��ȯ, �ս��� �Ͼ�� ����

    int num1 = 1000;
    char ch1 = num1; // demotion, narrowing conversion, ��� ��ȯ, �ս��� �Ͼ

    // Uniform initailization
    // { } �� �̿��Ͽ� �ʱ�ȭ�� �ϸ� ��� ��ȯ�� ��� ������ Ÿ�� ������ �߻��Ѵ�
    //char ch = { num1 };
    
    const int num2 = 10;
    char ch2{ num2 }; // num2�� int ���� ����̱� ������ ������ Ÿ�ӿ� ��ҵ��� �ʴ´ٴ� ���� �� �� �ִ�

    unsigned short s0 = 40000;
    cout << s0 + s0 << endl; // int�� promotion ��, int ���� ���� ������� int�� ��ȯ ��
    cout << typeid(s0 + s0).name() << endl;

    unsigned int i0 = 4100000000;
    cout << i0 + i0 << endl; // �ٸ� Ÿ������ ������ �ʰ� �����÷�
    cout << typeid(i0 + i0).name() << endl;

    unsigned int i1 = 10;
    int i2 = -110;
    cout << i0 + i2 << endl; // ����÷ο�, ���� Ÿ���� ���� �� unsigned �� �� ���� �پ������� ����� unsigned
    cout << typeid(i0 + i1).name() << endl;

    long long l0 = 10;
    cout << l0 + i1 << endl; // ū Ÿ������ ��ȯ�ȴ�
    cout << typeid(l0 + i1).name() << endl;

    // ����, �Ǽ��� ���� -> �Ǽ�
    // �Ǽ�, �Ǽ��� ���� -> �� ū Ÿ���� �Ǽ�

    // if, while, for, &&, ||, !, :? ���� bool�� �ʿ��� ���
    // ��ȯ ������, ��ȯ �����ڸ� explicit �� �����ϴ��� �ش� �ڸ������� �Ͻ������� ��ȯ ��

    // type -> const type ���δ� �Ͻ��� ��ȯ

    // �ڽ� ������(����)-> �θ� ������(����) Ÿ������ �Ͻ��� ��ȯ
}