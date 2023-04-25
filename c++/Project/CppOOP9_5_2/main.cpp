#include <iostream>
#include <vector>
#include "MoveString.h"


MoveString makeString(const char* str)
{
    return MoveString(str); // �̰��� ���簡 �Ͼ ������ �����Ͽ� std::move�� ������� ����. RVO ����ȭ
}

int main()
{
    std::vector<MoveString> s{ MoveString("abc") };
    std::cout << "resize" << std::endl;
    s.reserve(100); // MoveString�� �̵� ���� �Լ����� noexcept �� �����ϴ� ��� ���� �߻�


    makeString("abc");


    int num0 = 10;
    int& num1 = num0;
    int&& num2 = num0 + num1; // �ӽ� ���� ���� �� �ִ�

    //int& num3 = 3; // �ӽ� ���� ���� �� ����
    //int&& num4 = num0; // �ӽ� ���� �ƴϱ� ������ ���� �� ����
    //int&& num5 = num1; // �ӽ� ���� �ƴϱ� ������ ���� �� ����

    int& num6 = num2; // r-value reference �� l-value �̱� ������ ���� �� �ִ�
    //int&& num7 = num2; // r-value reference �� l-value �̱� ������ ���� �� ����
    int&& num8 = std::move(num0);

}