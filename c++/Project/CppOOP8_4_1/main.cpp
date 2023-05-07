#include <iostream>
#include <map>

using std::cout;
using std::endl;


int main()
{
    // Key, Value, Ʈ�� ���, ���� ���� O(log n)
    std::map<int, std::string> m;
    m[1] = "a";

    cout << m[1] << endl;
    cout << m[2] << endl; // ÷�� ���� ��ȸ �� Value�� ���� ��� Value�� �⺻ ���� ������ ��

    // map�� ���Ҵ� std::pair
    std::map<int, std::string> m0{
        {1, "1"},
        std::pair<int, std::string>(2, "2"),
        std::make_pair(3, "3")
    };

    // �׻� Key ������ ������ �Ǿ� �ִ�
    for (const std::pair<int, std::string>& pair : m0)
    {
        cout << pair.first << ":" << pair.second << endl;
    }

    std::map<int, std::string> m1;
    // ��� �� pair�� std::pair<int, std::string> �� �ƴ϶� std::pair<const int, std::string>
    // Tree���� Key�� �ٲ�� �� �Ǳ� ����
    for (const std::pair<int, std::string>& pair : m1) // ������ pair�� Ÿ���� �ٸ��� ������ ����ȯ�� �Ͼ
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const std::pair<const int, std::string>& pair : m1) // ������ const�� �ִ� pair�� �´� ǥ��
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const auto& pair : m1) // �Ǽ��� ���� �ϱ� ���� auto�� ���
    {
        cout << pair.first << ":" << pair.second << endl;
    }
}