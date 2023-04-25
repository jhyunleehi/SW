#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>

using std::cout;
using std::endl;


bool condition(const int& value)
{
    return value % 2 == 0;
}

int main()
{
    {
        // ����� ���� ����Ʈ
        std::list<int> list0{ 1, 2, 3 };
        // list0[2]; �� ��, Indexing ��ü�� O(n)�� �ɸ��� ������ �������� ����
        // stl�� ������(�������� ������) ������ �������� �ʴ´�.
        // Head <-> Node0 <-> Node1 <-> Tail

        std::list<int>::iterator iter = list0.begin();
        std::advance(iter, 2); // �̷��� �� �� ������ ���� ����
        cout << *iter << endl;
        
        list0.sort(); // sort �� ���� ����
        //std::sort(list0.begin(), list0.end()); ���� �׼��� ���ͷ����͸� �����ϴ� �����̳ʸ� ����


        // list�� �߰� ����, ������ ����
        list0.remove(2);
        list0.remove_if(condition); // ���ǿ� ������ ����
        cout << endl;

        
        std::list<int> list1{ 1, 1, 2, 3 };
        std::list<int> list2{ 1, 2, 3, 4 };

        // ���� �Ǿ� �ִ� �� ����Ʈ�� �����Ͽ� ����
        list1.merge(list2);
        for (int num : list1)
        {
            cout << num << endl;
        }
        cout << endl;

        // �ߺ� ����
        list1.unique();
        for (int num : list1)
        {
            cout << num << endl;
        }
        cout << endl;
    }
    {
        // �ܹ��� ���� ����Ʈ
        std::forward_list<int> list0{ 1, 2, 3, 4 };

        // ���� ������� �ʴ´�. ������ ����
    }
}

