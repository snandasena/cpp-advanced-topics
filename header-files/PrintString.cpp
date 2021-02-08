#include "PrintString.h"
#include <iostream>

void PrintString(std::string str, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << str << "\n";
    }
}
