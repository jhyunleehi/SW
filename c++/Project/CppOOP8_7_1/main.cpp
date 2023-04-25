#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using std::cout;
using std::endl;


// �Լ� ��ü
struct Func
{
    int operator()(int value) const
    {
        return value;
    }
};

int main()
{
    {
        Func func;
        cout << func(10) << endl;

        // lambda ��ü
        auto func0 = []()
        {
            return 10;
        };
        cout << func0() << endl;

        int num = 1;
        auto func1 = [num](int value) // num�� ĸ�� ��
        {
            return num + value;
        };
        cout << func1(10) << endl;
    }
    {
        // algorithm�� find ���
        std::vector<int> v{ 1, 2, 3, 4 };
        if (auto iter = std::find(v.begin(), v.end(), 4); iter != v.end())
        {
            cout << *iter << endl;
        }

        // ��� �Լ��� find ���
        std::set<int> s{ 1, 2, 3, 4};
        if (auto iter = s.find(4); iter != s.end())
        {
            cout << *iter << endl;
        }

        // ��� �Լ��� �ִ� ���� ��� �Լ��� �������


        // find_if �� set���� ��� �Լ��� ����. 
        std::find_if(s.begin(), s.end(), [](const int& value) {
            return (value % 2 == 0);
            });
    }
}