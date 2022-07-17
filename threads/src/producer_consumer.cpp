//
// Created by sajith on 7/16/22.
//
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

using namespace std;

class ServingLine
{
public:

    void server_soup(int i)
    {
        unique_lock ladle_lock(ladle);
        soup_que.push(i);
        ladle_lock.unlock();
        soup_served.notify_one();
    }


    int take_soup()
    {
        unique_lock ladle_lock(ladle);
        soup_served.wait(ladle_lock, [this]()
        { return !soup_que.empty(); });

        int bowl = soup_que.front();
        soup_que.pop();
        return bowl;
    }


private:
    mutex ladle;
    queue<int> soup_que;
    condition_variable soup_served;
};

void soup_producer(ServingLine &servingLine)
{
    for (int i = 0; i < 10000; ++i)
    {
        servingLine.server_soup(i);
    }

    servingLine.server_soup(-1);
    printf("Producer is done serving soup!\n");
}


void soup_consumer(ServingLine &servingLine)
{
    int soup_eaten = 0;
    while (true)
    {
        int bowl = servingLine.take_soup();
        if (bowl == -1)
        {
            printf("Consumer ate %d bowls of soup.\n", soup_eaten);
            servingLine.server_soup(-1);
            return;
        }
        else
        {
            soup_eaten += 1;
        }
    }
}


int main()
{

    ServingLine servingLine;

    thread olivia(soup_producer, ref(servingLine));
    thread barron(soup_consumer, ref(servingLine));
    thread steve(soup_consumer, ref(servingLine));

    olivia.join();
    barron.join();
    steve.join();
    return 0;
}