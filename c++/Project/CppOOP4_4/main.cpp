#include <iostream>

using std::cout;
using std::endl;


class Parent
{
public:
    virtual ~Parent() {}
};


class Child : public Parent
{
public:
    void func()
    {
        cout << "func" << endl;
    }
};


void func0(Parent* p)
{
    // ��� ���迡 ���� ��ȯ ����, virtual �Լ��� �� ���� �־�� dynamic_cast�� ��� ����
    // p�� ������ Parent�̸� ���ǵ��� ���� �ൿ
    //Child* child = dynamic_cast<Child*>(p); 
    //child->func();

    Child* child = dynamic_cast<Child*>(p);  // downcasting
    if (child != nullptr)
    {
        child->func();
    }

    // if �� ���� Ȱ��
    if (Child* child = dynamic_cast<Child*>(p)) // downcasting
        child->func();
}


void func1(Parent* p)
{
    // p�� Child�� �ƴ� ��� ���ܰ� �߻�, ���� try catch Ȱ��
    Child& child = dynamic_cast<Child&>(*p); //downcasting
    child.func(); 
}

int main()
{
    Parent* p = new Parent;
    func0(p);
    func1(p);

    // upcasting, �ڽ����� �θ�� ��ȯ (�Ͻ���)
    // downcasting, �θ� �ڽ����� ��ȯ (�����, ������ �� ����)
}