//
// Created by sajith on 7/17/21.
//

#include "Facade.h"
#include "A.h"
#include "B.h"
#include "C.h"

Facade::Facade()
{
    m_pA = new A{};
    m_pB = new B{};
    m_pC = new C{};
}

Facade::~Facade()
{
    delete m_pA;
    delete m_pB;
    delete m_pC;
}

void Facade::Use()
{
    m_pA->CallA();
    m_pB->CallB();
    m_pC->CallC();
}