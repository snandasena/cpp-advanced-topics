//
// Created by sajith on 7/11/21.
//

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <chrono>


using namespace std;

char WEEKDAYS[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Friday", "Saturday"};

int today = 0;
shared_mutex marker;

void CalendarReader(const int id)
{
    for (int i = 0; i < 7; ++i)
    {
        marker.lock_shared();
        printf("Reader-%d sees today is %s\n", id, WEEKDAYS[today]);
        this_thread::sleep_for(chrono::microseconds(100));
        marker.unlock_shared();
    }
}

void CalendarWriter(const int id)
{
    for (int i = 0; i < 7; ++i)
    {
        marker.lock();
        today = (today + 1) % 7;
        printf("Writer-%d updated date to %s\n", id, WEEKDAYS[today]);
        this_thread::sleep_for(chrono::microseconds(100));
        marker.unlock();
    }
}

int main()
{
    array<thread, 10> readers;
    for (size_t i = 0; i < readers.size(); ++i)
    {
        readers[i] = thread(CalendarReader, i);
    }

    array<thread, 2> writers;
    for (size_t i = 0; i < writers.size(); ++i)
    {
        writers[i] = thread(CalendarWriter, i);
    }

    for (auto &reader : readers)
    {
        reader.join();
    }

    for (auto &writer: writers)
    {
        writer.join();
    }

    return 0;
}