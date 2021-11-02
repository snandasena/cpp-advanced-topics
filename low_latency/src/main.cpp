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

    static void staticMethod()
    {
        cout << "Calling from a static method\n";
    }
};

void testMethod()
{
    cout << "Child thread " << this_thread::get_id() << endl;
}


int main()
{
    X x;
    thread t(&X::doSomthingInterest, &x, 10);
    cout << "Custom thread " << t.get_id() << endl;
    t.join();

    thread t1(X::staticMethod);
    t1.join();
    testMethod();
    cout << "Main thread " << this_thread::get_id() << endl;
    testMethod();
    return 0;
}