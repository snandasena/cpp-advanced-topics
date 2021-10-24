//
// Created by sajith on 10/24/21.
//

#include <iostream>
#include <future>
#include <chrono>

using namespace std;

void work(int id)
{
    for (int i = 0; i < 5; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Running.... " << id << endl;
    }
}


int main()
{
    future<void> res1 = async(launch::async, work, 0);
    future<void> res2 = async(launch::async, work, 1);

    cout<<thread::hardware_concurrency()<<endl;
    return 0;
}
