//
// Created by sajith on 5/22/21.
//

#include <thread>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::thread> threads;

    int numberof_thrads = 4;
    for (int i = 0; i < numberof_thrads; ++i)
    {
        threads.emplace_back(std::thread([]()
                                         {
                                             while (true);
                                         }));
    }

    std::for_each(threads.begin(), threads.end(), [](std::thread &t)
    {
        t.join();
    });

    return 0;
}