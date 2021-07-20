//
// Created by sajith on 7/20/21.
//


#include <string>
#include <iostream>

class Dog
{
    std::string m_name;

public:
    Dog(std::string name) : m_name(std::move(name)) {}

    void speak() const
    {
        std::cout << m_name << " barking...\n";
    }

};