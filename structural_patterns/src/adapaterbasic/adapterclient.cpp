//
// Created by sajith on 7/17/21.
//

#include "Target.h"
#include "Adapter.h"

void Client(Target *pTarget)
{
    pTarget->Request();
}


int main()
{
    Adapter adapter;
    Client(&adapter);

    return 0;
}