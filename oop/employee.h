//
// Created by sajith on 3/28/21.
//

#ifndef ADVANCED_TOPICS_EMPLOYEE_H
#define ADVANCED_TOPICS_EMPLOYEE_H

#include <iostream>
#include <string>

using std::string;


// delegating constructors

class Employee
{
private:
    int m_id{};
    string m_name{};

public:
    Employee(int id = 0, const string &name = "") : m_id{}, m_name{name}
    {
        std::cout << "Employee: " << m_name << " created\n";
    }

    Employee(const string &name) : Employee{0, name} {};
};


#endif //ADVANCED_TOPICS_EMPLOYEE_H
