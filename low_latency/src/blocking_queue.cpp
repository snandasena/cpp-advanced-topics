//
// Created by sajith on 11/5/21.
//
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <array>
#include <condition_variable>

template<typename T, size_t size>
class BlockingQueue
{
private:

    std::mutex _mtx;
    std::queue<T> _queue;
    std::condition_variable _condition;
    std::array<T, size> _data;
public:
    void push(T &item)
    {
        std::unique_lock<std::mutex> lock(_mtx);
        _condition.wait(lock, [this]() { return _queue.size() < size; });
        _queue.push(item);
        lock.unlock();
        _condition.notify_one();
    }

    void enqueue(T& elem)
    {

    }

    void dequeue()
    {

    }

    void pop()
    {
        std::unique_lock<std::mutex> lock(_mtx);
        _condition.wait(lock, [this]() { return !_queue.empty(); });
        _queue.pop();
        lock.unlock();
        _condition.notify_one();
    }

};

int main()
{
    BlockingQueue<int, 100> blockingQueue;
    std::thread t1([&]()
                   {
                       for (int i = 0; i < 100000; ++i)
                       {
                           blockingQueue.push(i);
                           printf("PUSHED %d\n", i);
                       }
                   });

    std::thread t2([&]()
                   {
                       for (int i = 0; i < 100000; ++i)
                       {
                           blockingQueue.pop();
                           printf("POPED\n");
                       }
                   });

    t1.join();
    t2.join();
    return 0;
}