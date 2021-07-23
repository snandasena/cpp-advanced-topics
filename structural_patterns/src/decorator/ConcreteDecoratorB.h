//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_CONCRETEDECORATORB_H
#define ADVANCED_TOPICS_CONCRETEDECORATORB_H

#include "Component.h"

class ConcreteDecoratorB : public Component
{

    Component *m_ptr;
public:

    ConcreteDecoratorB(Component *ptr) : m_ptr{ptr} {}

    void Operation() override;

};

#endif //ADVANCED_TOPICS_CONCRETEDECORATORB_H
