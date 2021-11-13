//
// Created by sajith on 11/13/21.
//

#include <iostream>
#include "Resource.h"

using std::cout;
using std::endl;

Resource::Resource(std::string _name) : name(_name)
{
    cout << "Constructing " << _name << endl;
}


Resource::~Resource()
{
    cout << "Destructing " << endl;
}