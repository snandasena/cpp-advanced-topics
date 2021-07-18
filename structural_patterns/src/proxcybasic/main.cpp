//
// Created by sajith on 7/17/21.
//


#include "RealSubject.h"
#include "Proxy.h"

void Operate(Subject *subject)
{
    subject->Request();
}

int main()
{
//    RealSubject *sub = new RealSubject;
    Subject *sub = new Proxy;
    Operate(sub);

    return 0;
}