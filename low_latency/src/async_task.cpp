//
// Created by sajith on 11/6/21.
//

#include <iostream>
#include <string>
#include <thread>
#include <future>
//#include <exception>

using namespace std;

string fun()
{
    string str{"Hello from thread!\n"};
    throw (runtime_error("Exception from task"));
//    return str;
}

int main()
{
    auto ftr = async(&fun);
    cout << "Hello from main!\n";

    try
    {
        string str = ftr.get();
        cout << str;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}

