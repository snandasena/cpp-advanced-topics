//
// Created by sajith on 7/17/21.
//

#include "Keyboard.h"


bool Keyboard::SimulateInput()
{
    std::bernoulli_distribution dist{0.5};

    return dist(m_Engine);
}

bool Keyboard::Up()
{
    return SimulateInput();
}

bool Keyboard::Down()
{
    return SimulateInput();
}

bool Keyboard::Left()
{
    return SimulateInput();
}

bool Keyboard::Right()
{
    return SimulateInput();
}