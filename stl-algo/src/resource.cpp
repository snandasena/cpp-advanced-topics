//
// Created by sajith on 11/25/21.
//

#include "resource.h"

int Resource::objectCount = 0;

Resource::Resource()
{
    ++objectCount;
}

Resource::Resource(const Resource &r)
{
    i = r.i;
    ++objectCount;
}

Resource &Resource::operator=(const Resource &r)
{
    i = r.i;
    return *this;
}

Resource::~Resource()
{
    --objectCount;
}