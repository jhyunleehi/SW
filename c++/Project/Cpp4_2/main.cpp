#include <iostream>
#include <compare>

using namespace std;
int main()
{
    {
        // Equal ������
        int num0 = 10, num1(10);
        if (num0 == num1)
            cout << "num0 == num1" << endl;
        
        // �Ʒ��� �Ǽ��鿡 ���� �Ѵ�.
        num0 = 10, num1 = 11;
        // if �� ���ΰ� 11�� �򰡵ǰ� 11�� true�� �򰡵Ǳ� ������ num0�� num1�� �޶� ������ ������ �ȴ�.
        if (num0 = num1)
            cout << "num0(10) = num1(11)" << endl;

        num0 = 0, num1 = 0;
        // if �� ���ΰ� 0���� �򰡵ǰ� 0�� false�� �򰡵Ǳ� ������ num0�� num1�� ���Ƶ� ������ �� �ȴ�.
        if (num0 = num1)
            cout << "num0(0) = num1(0)" << endl;
    }
    {
        // Not Equal ������
        int num0 = 0, num1(0);
        if (num0 != num1)
            cout << "num0(0) != num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 != num1)
            cout << "num0(0) != num1(1)" << endl;
    }
    {
        // > ������
        int num0 = 0, num1(0);
        if (num0 > num1)
            cout << "num0(0) > num1(0)" << endl;

        num0 = 1, num1 = 0;
        if (num0 > num1)
            cout << "num0(1) > num1(0)" << endl;
    }
    {
        // >= ������
        int num0 = 0, num1(0);
        if (num0 >= num1)
            cout << "num0(0) >= num1(0)" << endl;

        num0 = 1, num1 = 0;
        if (num0 >= num1)
            cout << "num0(1) >= num1(0)" << endl;
    }
    {
        // < ������
        int num0 = 0, num1(0);
        if (num0 < num1)
            cout << "num0(0) < num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 < num1)
            cout << "num0(0) < num1(1)" << endl;
    }
    {
        // <= ������
        int num0 = 0, num1(0);
        if (num0 <= num1)
            cout << "num0(0) <= num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 <= num1)
            cout << "num0(1) <= num1(0)" << endl;
    }
    {
        // SpaceShip ������
        // C++2x ���� ����. ������Ʈ �Ӽ����� C++ ��� ǥ�� ����
        cout.setf(ios_base::boolalpha);

        // <=> �� ����� 0�� ���� �� �ִ�.
        // 0�� ���ؼ� 0�� ������ <=>�� ����, ������ ����.
        // 0�� ���ؼ� 0���� ũ�� ������ ���׺��� ũ��.
        // 0�� ���ؼ� 0���� ������ ������ ���׺��� �۴�.
        cout << ((1 <=> 1) == 0) << endl;
        cout << ((2 <=> 1) > 0) << endl;
        cout << ((1 <=> 2) < 0) << endl;

        cout << is_eq(1 <=> 1) << endl;
        cout << is_gt(2 <=> 1) << endl;
        cout << is_lt(1 <=> 2) << endl;
        cout << is_gteq(2 <=> 1) << endl;
        cout << is_lteq(1 <=> 2) << endl;

        cout << typeid(1 <=> 1).name() << endl;
        cout << typeid(1 <=> 1.0).name() << endl;
    }
}