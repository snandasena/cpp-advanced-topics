//
// Created by sajith on 5/15/21.
//


#include <iostream>

void func(int &&val)
{

    std::cout << "val = " << val << std::endl;
}


int &GetVal()
{
    static int val = 10;
    return val;
}

void PrintVal(int &val)
{
    std::cout << "[l-value] " << val << "\n";
}

void PrintVal(const int &val)
{
    std::cout << "[l-value] " << val << "\n";
}

void PrintVal(int &&val) // rvalue reference
{
    std::cout << "[r-value] " << val << "\n";
}


int main()
{
    func(43);
    int i = 34;

    // cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
//    func(i);

    func(std::move(i));

    int a = GetVal();
    std::cout << a << "\n"; // 10
    GetVal() = 19;
    std::cout << GetVal() << "\n"; // 19

    a = 20;
    std::cout << GetVal() << "\n"; // 19

//    PrintVal(10);// Error
    int x = 10;
    int y = 20;
    PrintVal(x); // PrintVal(int &val)

    /*
     *  PrintVal(const int &val) will be overridden by rvalue reference method which is PrintVal(int &&val)
     */

    PrintVal(x + y); // PrintVal(const int &val)
    int z = x + y;
    PrintVal(z);

    /*
     * int &i = 10; compile error
     * const int &i = 10;
     * int temp = 10;
     * const int &i = temp;
     */

    return 0;
}
