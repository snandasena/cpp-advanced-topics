//
// Created by sajith on 5/14/21.
//

#include <iostream>

class MyClass
{
    int _mynumber;
public:

    MyClass()
    {
        std::cout << "Constructor is calling\n";
    }

    ~MyClass()
    {
        std::cout << "Destructor is calling";
    }

    void *operator new(size_t size)
    {
        std::cout << "new: Allocating " << size << "byte of memory\n";
        void *p = malloc(size);
        return p;
    }

    void operator delete(void *p)
    {
        std::cout << "delete: Memory is freed again\n";
        free(p);
    }
};


int main()
{
    MyClass *p = new MyClass;
    delete p;

    return 0;
}