//
// Created by sajith on 11/13/21.
//

#include "Person.h"

using namespace std;

Person::Person(std::string first, string last, int arbitrary) : firstname(first), lastname(last),
                                                                arbitraryNumber(arbitrary) {}

//Person::~Person()
//{
////    delete pResource;
//}

//Person::Person(const Person &rhs)
//{
//    pResource = new Resource(rhs.pResource->GetName());
//}

//Person &Person::operator=(const Person &rhs)
//{
//    delete pResource;
//    pResource = new Resource(rhs.pResource->GetName());
//    return *this;
//}

string Person::GetName() const
{
    return firstname + " " + lastname;
}


void Person::AddResource()
{
    pResource.reset();
    pResource = std::make_shared<Resource>("resource for " + GetName());
}