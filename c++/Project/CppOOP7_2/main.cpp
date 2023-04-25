#include <iostream>
#include <typeinfo>


using std::cout;
using std::endl;

class Parent
{
public:
    virtual ~Parent() {}
};

class Child : public Parent
{

};


int main()
{
    Parent* p = new Child;

    // ��Ÿ�� ���� ���� ���(RTTI) ���� �ʴ� ��� �Ʒ��� �ڵ尡 ������ ���� �ʴ´�
    // ��Ÿ�ӿ� ���� Ÿ���� �˾ƾ��ϴ� ���
    cout << typeid(*p).name() << endl; // p�� Ÿ���� ��Ÿ�ӿ� �� �� �ִ�
    dynamic_cast<Child*>(p); // p�� ĳ���� ���δ� ��Ÿ�ӿ� �� �� �ִ�.(�ٿ� ĳ����)

    // RTTI �� �����Լ� ���̺� ������ �ִ�.
    // typeid, dynamic_cast �� virtual �Լ��� ���� ��� ����� �������� ���� �� �ִ�.
}