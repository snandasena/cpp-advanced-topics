//
// Created by sajith on 7/19/21.
//

#ifndef ADVANCED_TOPICS_EMPLOYEE_H
#define ADVANCED_TOPICS_EMPLOYEE_H

#include <string>

class Employee
{
    std::string m_Name;
    std::string m_Role;

public:
    Employee(const std::string &name, const std::string &role);

    const std::string &GetName() const;

    const std::string &GetRole() const;

    std::string GetInfo() const;
};

#endif //ADVANCED_TOPICS_EMPLOYEE_H
