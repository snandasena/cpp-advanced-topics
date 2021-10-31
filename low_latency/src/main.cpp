//
// Created by sajith on 10/29/21.
//

#include <iostream>
#include <thread>

using namespace std;

class X
{

public:

    void doSomthingInterest(int num)
    {
        cout << num << " This is an interesting task 😂\n";
    }
};


int main()
{
    X x;
    thread t(&X::doSomthingInterest, &x, 10);
    t.join();

    return 0;
}