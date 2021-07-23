//
// Created by sajith on 7/23/21.
//

#ifndef ADVANCED_TOPICS_CONCRETEDECORATORB_H
#define ADVANCED_TOPICS_CONCRETEDECORATORB_H

#include "Decorator.h"

class ConcreteDecoratorB : public Decorator
{

    using Decorator::Decorator;
public:

    void OtherOperation();

    void Operation() override;

};

#endif //ADVANCED_TOPICS_CONCRETEDECORATORB_H
