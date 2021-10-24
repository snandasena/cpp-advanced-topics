//
// Created by sajith on 10/24/21.
//

#include <iostream>
#include <queue>
#include <condition_variable>
#include <thread>
#include <mutex>

using namespace std;

template<typename T>
class BlockingQueue
{
private:
    size_t _max_size;
    queue<T> _que;
    condition_variable _condition;
    mutex _mtx;
public:

    explicit BlockingQueue(size_t max_size) : _max_size{max_size}
    {

    }

    void push(T ele)
    {
        unique_lock<mutex> lock(_mtx);
        _condition.wait(lock, [this]() { return _que.size() < _max_size; });
        _que.push(ele);
        lock.unlock();
        _condition.notify_one();
    }

    T front()
    {
        unique_lock<mutex> lock(_mtx);
        _condition.wait(lock, [this]() { return !_que.empty(); });
        return _que.front();
    }

    void pop()
    {
        unique_lock<mutex> lock(_mtx);
        _condition.wait(lock, [this]() { return !_que.empty(); });
        _que.pop();
        lock.unlock();
        _condition.notify_one();
    }

    int size()
    {
        lock_guard<mutex> lock(_mtx);
        return _que.size();
    }

};

int main()
{
    BlockingQueue<int> bque(3);
    thread t1([&]()
              {
                  for (int i = 0; i < 10; ++i)
                  {
                      cout << "Pushing to the BQueue\n" << i;
                      bque.push(i);
                      cout << "Size of the BQueue " << bque.size() << endl;
                  }
              });
    thread t2([&]()
              {
                  for (int i = 0; i < 10; ++i)
                  {
                      cout << bque.front() << endl;
                      bque.pop();
                  }
              });

    t1.join();
    t2.join();
    return 0;
}