//
// Created by sajith on 10/28/21.
//

// No data races
// No allocations
// No locks

#include <iostream>
#include <array>
#include <atomic>
#include <thread>


template<typename T, size_t size>
class LockFreeQueue
{
public:

    bool push(const T &newElement)
    {
        auto oldWritePos = writePos.load();
        auto newWritePos = getPositionAfter(oldWritePos);
        if (newWritePos == readPos.load())
        {
            return false;
        }

        ringBuffer[oldWritePos] = newElement;
        writePos.store(newWritePos);
        return true;
    }

    bool pop(T &returnElement)
    {
        auto oldWritePos = writePos.load();
        auto oldReadPos = readPos.load();

        if (oldWritePos == oldReadPos)
        {
            return false;
        }

        returnElement = std::move(ringBuffer[oldReadPos]);
        readPos.store(getPositionAfter(oldReadPos));
        return true;
    }

private:

    static constexpr size_t getPositionAfter(size_t pos) noexcept
    {
        return ++pos == ringBufferSize ? 0 : pos;
    }

    static constexpr size_t ringBufferSize = size + 1;
    std::array<T, ringBufferSize> ringBuffer{};
    std::atomic<size_t> readPos{0}, writePos{0};
};

int main()
{
    LockFreeQueue<int, 10> lockFreeQueue;

    std::thread t1([&]()
                   {
                       for (int i = 0; i < 100000; ++i)
                       {
                           lockFreeQueue.push(i);
                           printf("PUSHED %d\n", i);
                       }
                   });

    std::thread t2([&]()
                   {
                       for (int i = 0; i < 100000; ++i)
                       {
                           lockFreeQueue.pop(i);
                           printf("POPED %d\n", i);
                       }
                   });

    t1.join();
    t2.join();

    return 0;
}