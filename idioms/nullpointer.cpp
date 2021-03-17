//
// Created by sajith on 3/16/21.
//

#include <iostream>

const
class NullPtrT
{
public:
    template<typename T>
    operator T *() const { return 0; }

    template<typename C, typename T>
    operator T C::*() const { return 0; };

private:
    void operator&() const;

} NullPtr;


struct X
{
    void f1();
};

void foo(int)
{
    std::cout << "foo int\n";
}

void foo(char *)
{
    std::cout << "foo char*\n";
}

int main()
{
    int *p = NullPtr;

    if (not p)
    {
        std::cout << "P is null\n";
    }

    if (p == NullPtr)
    {
        std::cout << "P is null\n";
    }

    int x = 10;
    int *p2 = &x;
    if (p2 != NullPtr)
    {
        std::cout << "P2 is not null\n";
    }

    foo(NullPtr);
    foo(nullptr);

//    foo(NULL); // error: call of overloaded ‘foo(NULL)’ is ambiguous foo(NULL);


    void (X::*fptr)() = NullPtr;

    return 0;
}