//
// Created by sajith on 7/17/21.
//

#include "Accelorometer.h"
#include <iostream>

double Accelerometer::GetHorizontalAxis()
{
    std::uniform_int_distribution<> dist{-10, 10};
    auto value = dist(m_Engine);
    std::cout << "[horizontal]  " << value << "\n";
    return value;
}

double Accelerometer::GetVerticalAxis()
{
    std::uniform_int_distribution<> dist{-10, 10};
    auto value = dist(m_Engine);
    std::cout << "[vertical]  " << value << "\n";
    return value;
}