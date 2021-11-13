//
// Created by sajith on 11/13/21.
//

#ifndef ADVANCED_TOPICS_PERSON_H
#define ADVANCED_TOPICS_PERSON_H

#include <string>
#include <memory>
#include "Resource.h"

class Person
{
private:
    std::string firstname;
    std::string lastname;
    int arbitraryNumber;
//    Resource *pResource{nullptr};
    std::shared_ptr<Resource> pResource;

public:

    Person(std::string first, std::string last, int arbitrary);

//    ~Person();

//    Person(Person const &rhs); // copy constructor

//    Person &operator=(Person const &rhs); // copy assignment

    std::string GetName() const;

    int GetNumber() const { return arbitraryNumber; }

    void SetNUmber(int number) { arbitraryNumber = number; }

    void SetFirstName(std::string first) { firstname = first; }

    void AddResource();

    std::string GetResourceName() const { return pResource ? pResource->GetName() : ""; }
};


#endif //ADVANCED_TOPICS_PERSON_H
