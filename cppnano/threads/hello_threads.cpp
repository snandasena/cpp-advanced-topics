//
// Created by sajith on 5/22/21.
//

#include <thread>
#include <iostream>

int main()
{
    std::cout << " Current thread " << std::this_thread::get_id() << "\n";

    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "This pc supports concurrency with " << cores << "\n";
    return 0;

}