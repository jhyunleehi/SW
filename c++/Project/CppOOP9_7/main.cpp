#include <iostream>
#include <memory>


struct Test
{
    int num;

    Test(int num) : num(num)
    {
        std::cout << "Construct : " << num << std::endl;
    }

    ~Test()
    {
        std::cout << "Destruct : " << num << std::endl;
    }
};

void foo0(std::unique_ptr<Test> p)
{

}

void foo1(const std::unique_ptr<Test>& p)
{

}

void foo2(Test* p)
{

}

struct B;
struct A
{
    A() { std::cout << "Construct A" << std::endl; }
    ~A() { std::cout << "Destruct A" << std::endl; }
    std::shared_ptr<B> b;
};

struct B
{
    B() { std::cout << "Construct B" << std::endl; }
    ~B() { std::cout << "Destruct B" << std::endl; }
 
    //std::shared_ptr<A> a; // ��ȣ ���� �� ���� �߻�
    std::weak_ptr<A> a; // ��ȣ ���� �� weak ptr �� ����ؾ� ������ �ȴ�.
};

struct Deleter
{
    void operator()(Test* test) const
    {
        std::cout << "custom delete : " << test->num << std::endl;
        delete test;
    } 
};
int main()
{
    {
        // Raw Pointer 
        int* num0 = new int(10);
        int* num1 = num0;

        delete num0;
        //delete num1; // ����ϱ� �����
    }


    // ����Ʈ ������ ����
    // unique_ptr, shared_ptr, weak_ptr

    {
        // unique_ptr - ���� ����

        std::unique_ptr<Test> p0(new Test(1)); // �ڵ� ���� ���� p�� ���� �� �� Test�� �������ش�
        auto p1 = std::make_unique<Test>(2);  // ���� ��Ȳ�� ��� make_unique�� �����ϴ� make_unique�� �������, C++14

        //std::unique_ptr<Test> p2 = p0;  // �� ��, ���� ������
        std::unique_ptr<Test> p2 = std::move(p0);  // �������� �̵�, p0�� �����

        foo0(std::move(p2)); // �������� �Ѱ���
        foo1(p1); // ������ ����
        foo2(p1.get()); // raw pointer�� ����

        Test* test = p1.release();  // ������ ����
        delete test;


        std::unique_ptr<Test, Deleter> p3(new Test(0)); // custom deleter 
    }

    {
        // shared_ptr - ���� ����
        std::shared_ptr<Test> s0(new Test(0));  // ���� ����, ���۷��� ī��Ʈ�� �̿��Ͽ� ���� ���� ����
        std::shared_ptr<Test> s1 = s0;

        std::cout << s0.use_count() << std::endl; // 2, s0, s1�� �����ϰ� �����Ƿ�
        std::cout << s1.use_count() << std::endl; // 2

    }
    {
        // weak_ptr

        // ��ȣ ����
        auto a = std::make_shared<A>();
        auto b = std::make_shared<B>();
        a->b = b;
        b->a = a;  // ��� ���� a�� weok_ptr�� ����Ͽ� ���� ī������ ������Ű�� �ʾ� ��ȣ ���� �ذ�

        auto p = std::make_shared<Test>(0);
        std::weak_ptr<Test> w = p;

        std::cout << p.use_count() << std::endl; // 1
        auto shared = w.lock();
        std::cout << p.use_count() << std::endl; // 2

        if (shared) // p�� ���� �����ƴٸ� if ���� ����� �� ����
        {
            std::cout << shared->num << std::endl;
        }
    }
}