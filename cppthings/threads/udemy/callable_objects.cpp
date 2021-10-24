//
// Created by sajith on 10/23/21.
//

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class App
{

private:
    int cnt = 0;
    mutex mx;
public:

    void operator()()
    {
        for (int i = 0; i < 1e7; ++i)
        {
            const std::lock_guard<mutex> lock(mx);
            ++cnt;
        }
    }

    int getCount() const { return cnt; }
};


int main()
{
    App app;
    app();
    cout << app.getCount() << endl;
    thread t1(std::ref(app));
    thread t2(std::ref(app));
    t1.join();
    t2.join();
    cout << app.getCount() << endl;
    return 0;
}