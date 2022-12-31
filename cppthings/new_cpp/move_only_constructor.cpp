//
// Created by sajith on 12/31/22.
//

#include <iostream>


class MyClass
{
};

class Test
{
private:
    int i{0};
    MyClass m;

public:

    Test() = default;

    Test(const Test &) = delete; // delete copy constructor
    Test &operator=(const Test &) = delete; // delete copy assignment

    Test(Test &&arg) noexcept: i(arg.i), m(std::move(arg.m))
    {
        std::cout << "Move constructor called\n";
    }

    Test &operator=(Test &&arg) noexcept
    {
        std::cout << "Move assignment operator called\n";
        if (this != &arg)
        {
            i = arg.i;
            m = std::move(arg.m);
        }
        return *this;
    }
};


class Test1
{
private:
    int i;
    MyClass m;

public:

    Test1() = default;

    Test1(Test1 &&arg) noexcept: i{arg.i}, m{std::move(arg.m)}
    {
        std::cout << "Called move constructor\n";
    }

    Test1 &operator=(Test1 &&arg) noexcept
    {
        std::cout << "Called move assignment\n";
        if (this != &arg)
        {
            i = arg.i;
            m = std::move(arg.m);
        }
        return *this;
    }
};

void TEST1()
{

    Test test;
    std::cout << "Moving temporary\n";

//    Test test_failed = test;
    Test test_move = Test(); // call move constructor by using temporary object
    std::cout << "Moving rvalue\n";
    Test test4(std::move(test)); // call move constructor by casting test rvalue
    std::cout << '\n';

//    Test test_assign;
//    test_assign = test; // call copy assignment operator

    Test test_assign;
    test_assign = Test(); // call move operator

    // lambda captures

//    Test lambda_capture;
//    [lambda_capture]() // use of deleted function
//    {
//        std::cout << "Lambda capturing...\n";
//    }();

}

void TEST2()
{
    Test1 test; // defalut constructor;
    Test1 test2(std::move(test));
    test2 = std::move(test);
//    Test1 test4(test); // use of deleted function
}

int main()
{
//    TEST1();
    TEST2();
}
