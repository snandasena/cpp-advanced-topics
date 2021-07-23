//
// Created by sajith on 7/23/21.
//

#include <iostream>
#include "ConcreteDecoratorB.h"

void ConcreteDecoratorB::Operation()
{
    std::cout << "[ConcreteDecoratorB] Operation invoked\n";
    m_ptr->Operation();
}