//
// Created by sajith on 11/13/21.
//

#include <iostream>
#include "Tweeter.h"

Tweeter::Tweeter(std::string first,
                 std::string last,
                 int arbitrary,
                 std::string handle) : Person(first, last,
                                              arbitrary),
                                       tweeterHandler(handle)
{
}

Tweeter::~Tweeter()
{
//    std::cout << "Calling Tweeter destructor\n";
}

std::string Tweeter::GetName() const
{
    return Person::GetName() + " " + tweeterHandler;
}
