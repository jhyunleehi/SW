#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>


using std::cout;
using std::endl;


int main()
{
    {
        std::vector<int> vector;
        vector.push_back(10);
        vector.push_back(20);
        vector.push_back(-1);

        // �־��ִ� ������� ���, Sequence Container
        cout << "vector" << endl;
        for (int num : vector)
            cout << num << endl;


        std::set<int> set;
        set.insert(10);
        set.insert(20);
        set.insert(-1);

        // ���ĵ� ������� ���, Ordered Associative Container
        cout << "set" << endl;
        for (int num : set)
            cout << num << endl;


        std::unordered_set<int> uset;
        uset.insert(10);
        uset.insert(20);
        uset.insert(-1);

        // ���������� �ȵ�, Unordered Associative Container
        cout << "unordered set" << endl;
        for (int num : uset)
            cout << num << endl;

    }
    {
        std::vector<int> nums{ 1, 2, 3, 4 };
        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << endl;
        }
        cout << endl;

        for (int num : nums)
        {
            cout << num << endl;
        }
        cout << endl;

        // ���ͷ����ʹ� ������ ������ ȣȯ�� ��
        for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) // [begin, end)
        {
            cout << *iter << endl;
        }
    }
    {
        std::vector<int> nums{ 10, 1, 2, 3, 4 };

        // �˰����� ����Ͽ� ����
        std::sort(nums.begin(), nums.end());

        for (int num : nums)
            cout << num << endl;
    }
}