//
// Created by sajith on 11/13/21.
//

#ifndef ADVANCED_TOPICS_PERSON_H
#define ADVANCED_TOPICS_PERSON_H

#include <string>

using std::string;

class Person
{

protected:
    string firstname;
    string lastname;
    int arbitraryNumber;

public:
    Person(const string &firstname, const string &lastname, int arbitraryNumber);
    virtual ~Person();

    virtual string GetName() const;

    virtual int GetNumber() const { return arbitraryNumber; }

    void SetNumber(int num) { arbitraryNumber = num; }

    void SetFirstName(string first) { firstname = first; }
};


#endif //ADVANCED_TOPICS_PERSON_H
