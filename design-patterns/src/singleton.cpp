//
// Created by sajith on 7/6/21.
//

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

class Singleton
{
protected:

    Singleton(string value) : value_(value) {}

    string value_;

    static Singleton *instance;

public:

    Singleton(Singleton &) = delete;

    void operator=(const Singleton &) = delete;

    static Singleton *GetInstance(const string &value);

    void SomeBusinessLogic()
    {
        cout << "Some business logic here\n";
    }

    string value() const
    {
        return value_;
    }
};

Singleton *Singleton::instance = nullptr;

Singleton *Singleton::GetInstance(const string &value)
{
    if (instance == nullptr)
    {
        instance = new Singleton(value);
    }

    return instance;
}

void ThreadFoo()
{
    this_thread::sleep_for(chrono::microseconds(1000));
    Singleton *singleton = Singleton::GetInstance("FOO");
    cout << singleton->value() << endl;
}


void ThreadBar()
{
    this_thread::sleep_for(chrono::microseconds(1000));
    Singleton *singleton = Singleton::GetInstance("BAR");
    cout << singleton->value() << endl;
}


int main()
{

    cout << "If you see the same value, then singleton was reused (yay!\n" <<
         "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
         "RESULT:\n";
    thread t1(ThreadFoo);
    thread t2(ThreadBar);

    t1.join();
    t2.join();

    return 0;
}