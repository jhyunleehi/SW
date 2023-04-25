#include <iostream>
#include <vector>
#include <list>
#include <set>

using std::cout;
using std::endl;


int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 3, 2, 1 };
    // ������ ������ �ʰ� ������ �ϴ� ���ҵ鸸ŭ ������ ����, ������� �״��
    // 1, 3, 4, 3, ?, ?
    auto iter = std::remove(v.begin(), v.end(), 2);

    // erase �� �ؾ� ��������
    v.erase(iter, v.end());

    for (auto num : v)
    {
        cout << num << endl;
    }

    // remove �� �������̾�� �ϱ� ������ array ��� ����ؾ��Ѵ�
    // array ��� ���� �迭�̱� ������ ����� ������ �� ����


    std::list<int> l{ 1, 2, 3, 4, 3, 2, 1 };
    l.remove(2); // list�� ��� ������ ������ �ְ� erase ���� �Ѵ�. 

    for (auto num : l)
    {
        cout << num << endl;
    }
    
    std::set<int> s{ 1, 2, 3, 4, 3, 2, 1 };
    //std::remove(s.begin(), s.end(), 2);  // �� ��
}