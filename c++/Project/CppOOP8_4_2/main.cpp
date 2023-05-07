#include <iostream>
#include <map>
#include <set>
#include <functional>

using std::cout;
using std::endl;


int main()
{
    {
        cout << std::boolalpha;

        std::map<int, std::string> m;
        std::pair<std::map<int, std::string>::iterator, bool> result = m.insert({ 3, "10" }); // �����ϴϱ� auto ���
        cout << result.second << endl; // ���� ����
        cout << result.first->first << endl; // �ش� Key�� ��ġ�ϴ� map�� �ִ� iterator
        cout << result.first->second << endl;


        // C++17����
        auto [iter, success] = m.insert({ 3, "20" });
        cout << success << endl;
        cout << iter->first << endl;
        cout << iter->second << endl;

        // C++17����
        for (auto& [key, value] : m)
        {
            value = "abc";
        }

        // ���ͷ����� ã��
        if (auto iter = m.find(3); iter != m.end())
        {
            cout << iter->second << endl; // ���ͷ����ͷ� �����
            m.erase(iter);
        }
        m.erase(3); // Ű�� �����
        cout << endl;
    }
    {
        // �ߺ� key ���
        std::multimap<int, std::string> mm{
            {2, "10"},
            {1, "10"},
            {1, "20"},
            {1, "30"},
        };

        for (const auto& [k, v] : mm)
        {
            cout << k << ":" << v << endl;
        }

        // �׻� ����
        mm.insert({ 1, "40" });
        
        // ���
        auto lower = mm.lower_bound(1);
        auto upper = mm.upper_bound(1);
        //auto [lower, upper] = mm.equal_range(1); // ���� ����
        for (auto iter = lower; iter != upper; ++iter)
        {
            cout << iter->second << endl;
        }
    }
    {
        // Ʈ�� ����. Key�� ����, ���� �Ǿ� ����
        std::set<int> s{
            1, 2, 3, 4
        };

        if (auto [iter, success] = s.insert(10); success)
        {
            cout << *iter << endl;
        }
    }
    {
        // Ʈ�� ����. Key�� ����, ���� �Ǿ� ����, �ߺ� ���
        std::multiset<int> ms{
            1, 1, 3, 10, 10, 3
        };
        for (const auto& num : ms)
        {
            cout << num << endl;
        }
    }
    {
        // std::less<int> ������ ��� ���� �����ϴ� �Լ� ��ü
        std::set<int, std::less<int>> s;
        std::map<int, std::string, std::less<int>> m;

        std::set<int, std::less<int>> s0{ 3, 10, -1 };
        std::set<int, std::greater<int>> s1{ 3, 10, -1 };

        // ��������
        for (const auto& num : s0)
        {
            cout << num << endl;
        }

        // ��������
        for (const auto& num : s1)
        {
            cout << num << endl;
        }

    }
}