#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


class Shape
{

};

// Shape - Rectangle : is-a ����
class Rectangle : public Shape
{

};

// deque ������ �½��ϴ�. ���ǿ� ���� �κ��� �߸� �ƽ��ϴ�
// Queue - deque : has-a ����
class Queue0
{
private:
    deque<int> v;
public:
    void push(int value)
    {
        v.push_back(value);
    }

    void pop()
    {
        v.pop_front();
    }

    int top()
    {
        return v.front();
    }
};


// public ����� deque�� ��� �������̽��� public���� ����Ѵ�.
// private ����� deque�� ��� �������̽��� private���� ����Ѵ�.
// ���� Queue1������ deque�� ������ø� ����� �� ������ �ܺο����� ����� �� ����
// �ظ��ϸ� ������� ����.
// deque�� protected ��� �Լ��� ����ϰ� ���� ��� ����ϸ� ����
// �����ڸ� �����ϸ� private ���(struct�� ���� public)

class Queue1 : private deque<int>
{
public:
    void push(int value)
    {
        push_back(value);
    }

    void pop()
    {
        pop_front();
    }

    int top()
    {
        return front();
    }
};


// deque�� �������̽��� Queue2�� �ڽĿ��Ա��� �����ϱ� ���� protected ����� �Ѵ�
class Queue2 : protected deque<int>
{
public:
    virtual void push(int value)
    {
        push_back(value);
    }

    virtual void pop()
    {
        pop_front();
    }

    virtual int top()
    {
        return front();
    }

    virtual ~Queue2()
    {

    }
};


class PriorityQueue : public Queue2
{
public:
    virtual void push(int value) override
    {
        Queue2::push(value);
        push_heap(begin(), end());
    }

    virtual void pop() override
    {
        pop_heap(begin(), end());
        Queue2::pop_back();
    }

    virtual int top() override
    {
        return front();
    }
};



int main()
{
    PriorityQueue pq;
    pq.push(10);
    pq.push(100);
    pq.push(0);


    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();

    cout << pq.top() << endl;
    pq.pop();
}