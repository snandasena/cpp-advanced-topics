//
// Created by sajith on 7/23/21.
//

#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

// client code
void Operate(Component *component)
{
    component->Operation();
}

int main()
{

    ConcreteComponent component;
    ConcreteDecoratorA decA{&component};
    decA.Operation();

    ConcreteDecoratorB decB{&decA};
    decB.Operation();
    decB.OtherOperation();

    Operate(&decB);

    return 0;
}