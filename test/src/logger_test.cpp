//
// Created by sajith on 1/14/22.
//

#include <thread>
#include "Logger.h"

void api(sdn::Logger &log)
{
    for (int i = 0; i < 100000; ++i)
    {
        log.log("Hello from API" + std::to_string(i) + '\n');
    }
}

int main()
{
    sdn::Logger logger("temp.txt");
    std::thread t(api, std::ref(logger));

    for (int i = 0; i < 100000; ++i)
    {
        logger.log("Hello from main " + std::to_string(i) + '\n');
    }
    t.join();
    return 0;
}