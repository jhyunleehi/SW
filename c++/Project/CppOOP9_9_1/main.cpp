#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <atomic>
#include <queue>

using namespace std::chrono_literals;

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
thread_local Test test(10);  // thread ���� ��ŭ ���� ��

void loop0()
{
    for (int i = 0; i < 10; ++i)
    {
        thread_local int num = 10;  // thread ���� �� �� �ʱ�ȭ ��, static�� thread �� ���� ���� �� �� �ʱ�ȭ
        num++;
        std::cout << num << std::endl;
    }
}


int num = 0;
void loop1()
{
    for (int i = 0; i < 1000000; ++i)
    {
        num++;
    }

}

void longTimeJob()
{
    std::this_thread::sleep_for(200ms);
}

void produce(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue)
{
    while (true)
    {
        std::this_thread::sleep_for(100ms);
        {
            std::lock_guard<std::mutex> lock(m);
            jobQueue.push(1);
            std::cout << "produce : " << jobQueue.size() << std::endl;
        }
        cv.notify_one();
    }
}

void consume(std::mutex& m, std::condition_variable& cv, std::queue<int>& jobQueue)
{
    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(m);
            if (jobQueue.empty())  // lost wakeup
            {
                cv.wait(lock);
            }

            if (jobQueue.empty())  // spurious wakeup
            {
                continue;
            }

            int result = jobQueue.front();
            jobQueue.pop();

            std::cout << "consume : " << jobQueue.size() << std::endl;
        }
        longTimeJob();
    }
}



int main()
{
    {
        // thread �⺻���� ����
        std::cout << "thread ID: " << std::this_thread::get_id() << std::endl;

        // callable ����
        std::thread th([] {
            std::cout << "thread ID: " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(1s);
            });
        th.join();

        std::cout << "Complete" << std::endl;
    }
    {
        // thread local ���
        std::thread th(loop0);
        loop0();
        th.join();
    }
    {
        std::thread th(loop1);
        loop1();
        th.join();

        std::cout << num << std::endl; // �׻� 2000000 �� ������ �ʴ´�

        // num += 1 ����
        // 1. load num to register
        // 2. register += 1
        // 3. store register to num

        // �Ʒ��� ���� ��Ȳ�� �߻��� �� ����
        // thread0     thread1
        // 1. load(0)
        //             1. load(0)
        // 2. reg(1)   2. reg(1)
        // 3. store(1) 3. store(1)
    }
    {
        // lock

        std::mutex m;
        int num = 0;
        auto func = [&num, &m]
        {
            for (int i = 0; i < 1000000; ++i)
            {
                // �Ӱ� ���� ����
                m.lock();
                num++;
                m.unlock(); // �Ӱ� �������� ���� �߻� �� ������� ����, std::lock_guard �� �̿��Ͽ� ������ ����
            }
        };

        std::thread th0(func);
        std::thread th1(func);

        th0.join();
        th1.join();
        std::cout << num << std::endl;  // 2000000
    }
    {
        // atomic
        // lock �� ��� ��
        std::atomic_int num = 0;
        auto func = [&num]
        {
            for (int i = 0; i < 1000000; ++i)
            {
                num++;
            }
        };

        std::thread th0(func);
        std::thread th1(func);

        th0.join();
        th1.join();
        std::cout << num << std::endl;  // 2000000
    }
    {
        // producer, consumer
        std::mutex m;
        std::condition_variable cv;
        std::queue<int> jobQueue;
        std::thread producer(produce, std::ref(m), std::ref(cv), std::ref(jobQueue));
        std::thread consumer0(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));
        std::thread consumer1(consume, std::ref(m), std::ref(cv), std::ref(jobQueue));

        producer.join();
        consumer0.join();
        consumer1.join();
    }
}