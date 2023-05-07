#include <iostream>
#include <vector>
#include <map>
#include <type_traits>

using std::cout;
using std::endl;

class Person {};
int func(float) { return 0; }

template<typename T, typename S>
void add0(T t, S s)
{
    auto r = t + s;
    std::cout << r << std::endl;
}

template<typename T, typename S>
auto add1(T t, S s) -> decltype(t + s) // C++14���� ��������
{
    return t + s;
}

enum class Type
{
    A, B
};

template<typename Enumeration>
auto asInteger(Enumeration value) -> typename std::underlying_type<Enumeration>::type // C++14���� ��������
{
    return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

int main()
{
    auto i = 10; // int ��, ������ Ÿ�� �߷�, ���ø��� Ÿ���߷а� ���� ����
    auto j = 1u; // unsigned int


    std::vector<int> v;
    std::vector<int>::iterator iter0 = v.begin();
    auto iter1 = v.begin();  // �� ���� ���������� �����ϴ�. ���� ��� Ÿ���� �ʹ� ��Ȳ��

    Person* person0 = new Person;
    auto person1 = new Person; // �º��� Person�� �����Ͽ� �ߺ����� �ʴ´�.

    std::map<int, int> m;
    for (const std::pair<int, int>& pair : m) {} // ��ȸ�� ������ �ùٸ��� ����, �ӽ� ��ü(pair)�� ���� ��
    for (const std::pair<const int, int>& pair : m) {} // �ùٸ� Ÿ��
    for (const auto& pair : m) {} // auto ��� �� key ���� �Ű澲�� �ʾƵ� ��. �Ǽ��� �پ��


    const int a = 10;
    const int& b = a;
    const int* c = &a;

    auto aa = a; // int
    auto bb = b; // int, ������ �߷е��� �ʰ� ������ �߷� ��
    auto cc = c; // const int*

    auto& dd = b; // const int&, const int�� �߷� �ǰ� &�߰�
    auto* ee = c; // const int*, const int�� �߷� �ǰ� *�߰�

    const auto& ff = b; // const int&, int�� �߷� �ǰ� const, & �߰�

    int nums[] = { 1, 2, 3 };
    auto num0 = nums; // int*
    auto& nums1 = nums; // int(&)[3]

    auto func0 = func; // int (*)(float)
    auto& func1 = func; // int (&)(float)

    add0(1, 1.2);
    add1(1, 1.2);

    asInteger(Type::A);
}