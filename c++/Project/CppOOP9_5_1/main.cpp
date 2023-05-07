#include <iostream>
#include "MoveString.h"
#include "NotMoveString.h"


template<typename T>
void swapCopy(T& x, T& y)
{
    T temp = x; // �ӽ� ��ü�� �����ϴ� ���
    x = y;
    y = temp;
}


template<typename T>
void swapMove(T& x, T& y)
{
    T temp = std::move(x); // ������ �̵�,
    x = std::move(y);
    y = std::move(temp);
}

int main()
{
    NotMoveString nms0("abc");
    nms0 = NotMoveString("def"); // ���� ��� �߻�


    MoveString  ms0("abc");
    ms0 = MoveString("def"); // ���� ��� �߻� ���� ����, �̵�
    MoveString ms1("def");
    ms0 = ms1;  // �̵����� �ʰ� ����, ms1 �� ���Ŀ� ���� �� �ֱ� ����

    swapCopy(ms0, ms1);
    swapMove(ms0, ms1);
}