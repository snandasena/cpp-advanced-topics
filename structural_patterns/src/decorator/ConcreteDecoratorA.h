//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_CONCRETEDECORATORA_H
#define ADVANCED_TOPICS_CONCRETEDECORATORA_H

#include "Decorator.h"

class ConcreteDecoratorA : public Decorator
{
    using Decorator::Decorator;
public:

    void Operation() override;
};

#endif //ADVANCED_TOPICS_CONCRETEDECORATORA_H
