//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_DECORATOR_H
#define ADVANCED_TOPICS_DECORATOR_H

#include "Component.h"

class Decorator : public Component
{

    Component *m_ptr;

public:
    Decorator(Component *ptr) : m_ptr{ptr} {}


    void Operation() override = 0;
};

#endif //ADVANCED_TOPICS_DECORATOR_H
