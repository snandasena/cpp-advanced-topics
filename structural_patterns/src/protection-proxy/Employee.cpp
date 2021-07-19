//
// Created by sajith on 7/19/21.
//

#include "Employee.h"
#include <sstream>

Employee::Employee(const std::string &name, const std::string &role) : m_Name(name), m_Role(role)
{

}

const std::string &Employee::GetName() const
{
    return m_Name;
}


const std::string &Employee::GetRole() const
{
    return m_Role;
}

std::string Employee::GetInfo() const
{
    std::ostringstream out;

    out << '[' << m_Role << ']' << m_Name << ' ';
    return out.str();
}