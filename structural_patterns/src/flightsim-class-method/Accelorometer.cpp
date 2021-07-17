//
// Created by sajith on 7/17/21.
//

#include "Accelorometer.h"
#include <iostream>

double Accelerometer::GetHorizontalAxis()
{
    auto init_values = Initialize();
    std::uniform_int_distribution<> dist{init_values.first, init_values.second};
    auto value = dist(m_Engine);
    std::cout << "[horizontal]  " << value << "\n";
    return value;
}

double Accelerometer::GetVerticalAxis()
{
    auto init_values = Initialize();
    std::uniform_int_distribution<> dist{init_values.first, init_values.second};

    auto value = dist(m_Engine);
    std::cout << "[vertical]  " << value << "\n";
    return value;
}

std::pair<int, int> Accelerometer::Initialize()
{
    return {-10, 10};
}