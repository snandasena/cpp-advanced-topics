//
// Created by sajith on 5/29/21.
//

#include <iostream>
#include <future>
#include <mutex>
#include <queue>
#include <algorithm>

template<class T>
class MessageQueue
{
public:
    T receive()
    {
        std::unique_lock<std::mutex> ulock(_mutex);
        _cond.wait(ulock, [this]
        {
            return !_messages.empty();
        });

        T msg = _messages.back();
        _messages.pop_back();
        return msg;
    }

    void send(T &&msg)
    {
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        std::lock_guard<std::mutex> lock(_mutex);

        std::cout << " Message " << msg << " has been sent to the quque\n";
        _messages.push_back(msg);
        _cond.notify_one();
    }

private:
    std::mutex _mutex;
    std::condition_variable _cond;
    std::deque<T> _messages;
};


int main()
{
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);
    std::cout << "Spawning threads...\n";

    std::vector<std::future<void>> futures;

    for (int i = 0; i < 10; ++i)
    {
        int message = i;
        futures.emplace_back(std::async(std::launch::async, &MessageQueue<int>::send, queue, message));
    }

    std::cout << "Collecting results...\n";

    while (true)
    {
        int message = queue->receive();
        std::cout << "Message #" << message << " has been removed from the queue\n";
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr)
    {
        ftr.wait();
    });

    std::cout << "Finished!\n";
    return 0;
}