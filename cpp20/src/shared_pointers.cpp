//
// Created by sajith on 9/23/22.
//
#include <memory>
#include <iostream>
#include <string>

using namespace std;


void Test1()
{

    shared_ptr<int> ptr{new int{10}};
    cout<< ptr.use_count()<<endl;
    shared_ptr<int> ptr2 = ptr;
    cout<< ptr.use_count()<<endl;
    cout<< ptr2.use_count()<<endl;

    shared_ptr<int> ptr3{ptr2};
    cout<<ptr3.use_count()<<endl;
}

int main()
{
    Test1();
    return 0;
}