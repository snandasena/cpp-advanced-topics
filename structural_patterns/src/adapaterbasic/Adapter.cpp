//
// Created by sajith on 7/17/21.
//

#include <iostream>
#include "Adapter.h"

void Adapter::Request()
{
    std::cout << "[Adapter] Calling SpecificRequest\n";
    m_Adaptee.SpecificRequest(); // composition
    SpecificRequest(); // Inheritance
}
