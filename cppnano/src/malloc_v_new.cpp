//
// Created by sajith on 5/14/21.
//

#include <stdlib.h>
#include <iostream>

class MyClass
{
private:
    int *_number;

public:
    MyClass()
    {
        std::cout << "Allocate memory\n";
        _number = (int *) malloc(sizeof(int));
    }

    ~MyClass()
    {
        std::cout << "Delete memory\n";
        free(_number);
    }

    void setNumber(int number)
    {
        *_number = number;
        std::cout << "Number: " << _number << "\n";
    }
};


int main()
{
    // allocate memory using malloc
    // comment these lines out to run the example below
//    MyClass *myClass = (MyClass *) malloc(sizeof(MyClass));
//    myClass->setNumber(42); // EXC_BAD_ACCESS
//    free(myClass);

    void *memory = malloc(sizeof(MyClass)); // pre memory allocation
    MyClass *myClass1 = new(memory)MyClass; // placement new
    myClass1->setNumber(42); // work as expected
    free(myClass1);

    // allocate memory using new
    MyClass *myClass2 = new MyClass();
    myClass2->setNumber(42); // works as expected
    delete myClass2;

    return 0;
}