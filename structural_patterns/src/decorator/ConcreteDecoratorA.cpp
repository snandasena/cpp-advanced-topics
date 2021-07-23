//
// Created by sajith on 7/23/21.
//

#include <iostream>
#include "ConcreteDecoratorA.h"


void ConcreteDecoratorA::Operation()
{
    std::cout << "[ConcreteDecoratorA] Operation invoked\n";
    m_ptr->Operation();
}