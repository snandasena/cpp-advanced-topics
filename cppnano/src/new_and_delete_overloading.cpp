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
        std::cout << "Destructor is calling\n";
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

    void *operator new[](size_t size)
    {
        std::cout << "new: Allocating " << size << " bytes of memory" << std::endl;
        void *p = malloc(size);
        return p;
    }

    void operator delete[](void *p)
    {
        std::cout << "delete: Memory is freed again " << std::endl;
        free(p);
    }
};


int main()
{
    MyClass *p = new MyClass;
    delete p;

    MyClass *p1 = new MyClass[3]();
    delete[] p1;
    return 0;
}