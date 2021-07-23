//
// Created by sajith on 7/23/21.
//

#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

int main()
{

    ConcreteComponent component;
    ConcreteDecoratorA decA{&component};
    decA.Operation();

    ConcreteDecoratorB decB{&decA};
    decB.Operation();
    return 0;
}