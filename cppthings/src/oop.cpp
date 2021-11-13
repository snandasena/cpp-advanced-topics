//
// Created by sajith on 11/12/21.
//
#include <vector>
#include <iostream>

using namespace std;

struct base
{

    using X = int;
};

struct derived final : base
{
    int X;
//    vector<X> v;
};


struct Logger
{
    Logger()
    {
        LoggerMessage("Log created!\n");
    }

    virtual void LoggerMessage(char const *message) = 0;

    virtual ~Logger() = default;
};


struct ConsoleLogger final : Logger
{
    virtual void LoggerMessage(char const *message) override
    {
        cout << "Message here\n";
    }
};


struct Test
{
private:
    int mutable member{0};

public:
    int getMember() const
    {
        member += 10;
        return member;
    }
};


struct Person
{
    char const *name;
    int age;
};

int main()
{

//    ConsoleLogger cl;

    int x = 10;
    cout << &x << endl;

    int *pX = &x;
    cout << pX << endl;

    Test test;
    cout << test.getMember() << endl;

    int y = 10;
    int *pInt = &y;

    int const *pInt1 = &y;
    pInt1 = &x;

//    *pInt1 = 10;

    cout << *pInt1 << endl;
    const int *pInt2 = &y;
    pInt2 = &x;
    cout << *pInt2 << endl;

//    *pInt2 = 10;

    int const *const pInt3 = &y;
//    pInt3 = &x;


    int i = 10;
    int *pI = &i;
//    int *pII = &pI;

    Person p{"name", 10};
//    pI = &p;

    int const *pcI = pI;
//    *pcI = 10;

    int *const cpI = pI;
//    cpI = &i;
    *cpI = 30;

    int const *const cpcI = pI;
//    *cpcI = 10;
//    cpcI = &i;
    return 0;
}