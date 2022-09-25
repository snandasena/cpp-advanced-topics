//
// Created by sajith on 9/23/22.
//
#include <memory>
#include <iostream>
#include <string>

using namespace std;

class A
{
public:
    A()
    {
        cout << "default constructor\n";
    }

    A(int _x) : x{_x}
    {
        cout << "parameterized constructor\n";
    }

    ~A()
    {
        cout << "destructor\n";
    }

    A(const A &other) : x{other.x}
    {
        cout << "copy constructor\n";
    }

    A &operator=(const A &)
    {
        cout << "copy assignment\n";
        return *this;
    }

    A(const A &&)
    {
        cout << "move constructor\n";
    }

    void print_info()
    {
        cout << "x = " << x << endl;
    }
private:

    int x{0};
};

void Test1()
{

    shared_ptr<int> ptr{new int{10}};
    cout << ptr.use_count() << endl;
    shared_ptr<int> ptr2 = ptr;
    cout << ptr.use_count() << endl;
    cout << ptr2.use_count() << endl;

    shared_ptr<int> ptr3{ptr2};
    cout << ptr3.use_count() << endl;

    ptr.reset();
    cout << ptr3.use_count() << endl;

    int *x = new int{10};
    shared_ptr<int> p{x};

    cout << *p << endl;
//    p.reset();
//    delete x;

}

void API1(shared_ptr<A> ptr)
{
    ptr->print_info();
    cout << "API1 use count: " << ptr.use_count() << endl;
}


void API3(shared_ptr<A> &ptr)
{
    ptr->print_info();
    cout << "API3 use count: " << ptr.use_count() << endl;
}


void Test2()
{
    auto ptr = make_shared<A>(10);
    cout << "caller use count : " << ptr.use_count() << endl;
    API1(ptr);
    API3(ptr);
}

void API2(A a)
{
    a.print_info();
}

void Test3()
{
    A a{1000};
//    A b{a};
//    b.print_info();
    API2(a);
}


int main()
{
//    Test1();

    Test2();

//    Test3();
    return 0;
}