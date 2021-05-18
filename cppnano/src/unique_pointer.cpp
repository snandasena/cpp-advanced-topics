//
// Created by sajith on 5/18/21.
//

#include <memory>
#include <iostream>
#include <string>

void raw_pointer()
{
    int *raw = new int; // create a raw pointer on the heap
    *raw = 1; // assign a value
    delete raw; // delete the resource again
}

void unique_pointer()
{
    std::unique_ptr<int> unique(new int); // create a unique pointer on the stack
    *unique = 2;// assign a value
    // delete is not necessary
}

class MyClass
{
private:
    std::string _text;

public:
    MyClass() {}

    MyClass(std::string text)
    {
        _text = text;
    }

    ~MyClass()
    {
        std::cout << _text << " destroyed\n";
    }

    void setText(std::string text)
    {
        _text = text;
    }
};

int main()
{

    // create unique pointers to proprietary class
    std::unique_ptr<MyClass> myClass1(new MyClass);
    std::unique_ptr<MyClass> myClass2(new MyClass("string 2"));

    // call member function
    myClass1->setText("string 1");

    // use the dereference operator *
    *myClass1 = *myClass2;

    std::cout << "Objects have stack address " << myClass1.get() << " and " << myClass2.get() << "\n";

    return 0;
}