//
// Created by sajith on 11/13/21.
//

#include "Person.h"


int main()
{
    Person kate("Kate", "Gregory", 3544);
    kate.AddResource();
    kate.AddResource();

    Person kate2 = kate;
    kate2.AddResource();

    return 0;
}