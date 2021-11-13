//
// Created by sajith on 11/13/21.
//
#include <iostream>
#include "Person.h"

Person::Person(const string &firstname, const string &lastname, int arbitraryNumber) : firstname(firstname),
                                                                                       lastname(lastname),
                                                                                       arbitraryNumber(
                                                                                           arbitraryNumber) {}

Person::~Person()
{
//    std::cout << "Calling Person destructor\n";
}

string Person::GetName() const
{
    return firstname + " " + lastname;
}