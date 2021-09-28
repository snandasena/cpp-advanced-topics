//
// Created by sajith on 9/28/21.
//

#include "base.h"

class Person
{
public:
    Person(string name)
    {
        pName_ = new string(name);
    }

    ~Person()
    {
        delete pName_;
    }
//
//    Person(const Person &rhs) // copy constructor
//    {
//        pName_ = new string(*rhs.pName());
//    }
//
//    Person &operator=(const Person &rhs); // copy operator

    string *pName() const
    {
        return pName_;
    }

    void printName()
    {
        cout << *pName_ << endl;
    }

    Person *clone()
    {
        return (new Person(*(pName_)));
    }

private:
    string *pName_;
    Person(const Person &rhs);
    Person &operator=(const Person &rhs); // copy operator

};

// Solution 1: Define copy constructor and copy assigment operator for deep copying
// Solution 2: Define copy constructor and copy assigment operator, define clone().

int main()
{
//    vector<Person> persons;
    vector<Person *> persons;
    persons.push_back(new Person("George"));
    persons.back()->printName();
    cout << "Good bye" << endl;
    return 0;
}