//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_CONCRETEDECORATORA_H
#define ADVANCED_TOPICS_CONCRETEDECORATORA_H

#include "Component.h"

class ConcreteDecoratorA : public Component
{

    Component *m_ptr;

public:
    ConcreteDecoratorA(Component *ptr) : m_ptr{ptr} {}

    void Operation() override;
};

#endif //ADVANCED_TOPICS_CONCRETEDECORATORA_H
