#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::endl;


int main()
{
    {
        std::vector<int> vec{ 1, 2, 3 };
        std::vector<int>::iterator iter = vec.begin();
        int* num = &vec[0];

        // vector�� ����� ũ�� ��ŭ Ŀ�� �� �� �� �ִٸ� reserve�� �̸� ������
        vec.reserve(vec.capacity() + 1);

        // ���� �ּҰ� �ٸ���.
        cout << num << endl;
        cout << &vec[0] << endl;

        // ��ü�� �ð� ���⵵ O(1), ���Ҵ� �� ���� ������ ����
        vec.push_back(10);

        // �ð� ���⵵ O(1)
        vec.pop_back();

        // ���� �տ� �����߱� ������ O(n), �ڷ� �� �и�
        vec.insert(vec.begin(), 10);

        // [1, 2, 3, ?] 
        // size = 3
        // capacity = 4

        // push_back(4)
        // [1, 2, 3, 4]
        // size = 4
        // capacity = 4

        // push_back(5)
        // [1, 2, 3, 4, 5, ?, ?, ?] // �迭�� ���Ҵ�
        // size = 4
        // capacity = 8
    }
    {
        std::deque<int> nums;

        // ��ü�� O(1)
        nums.push_front(1);

        // ��ü�� O(1)
        nums.push_back(2);

        // push_back
        // [0]

        // push_front
        // [1] [0]
        // push_front �� ������ ����� ���ؼ� �迭�� �� �����.
    }
}
