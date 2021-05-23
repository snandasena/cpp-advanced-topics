//
// Created by sajith on 5/23/21.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <future>


void modify_message(std::promise<std::string> &&prms, std::string message)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // simulate work
    std::string modified_message = message + " modified";
    prms.set_value(modified_message);
}

int main()
{

    std::string messageToThread = "My message";

    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    // start thread and pass promise as argument
    std::thread t(modify_message, std::move(prms), messageToThread);

    // print message to console
    std::cout << "Original message from main(): " << messageToThread << std::endl;

    // retrieve from thread via future and print to console
    std::string messageFromThread = ftr.get();

    std::cout << "Modified message from thread(): " << messageFromThread << std::endl;

    // thread barrier
    t.join();

    return 0;
}