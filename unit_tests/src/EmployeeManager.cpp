//
// Created by sajith on 10/19/22.
//

#include "EmployeeManager.h"


EmployeeManager::EmployeeManager(IDatabaseConnection *dbConnection) : mDatabaseConnection{dbConnection}
{
    mDatabaseConnection->connect();
}


EmployeeManager::~EmployeeManager()
{
    mDatabaseConnection->disconnect();
}

float EmployeeManager::getSalary(int empId) const
{
    return mDatabaseConnection->getSalary(empId);
}

void EmployeeManager::setSalary(int employeeId, float newSalary)
{
    mDatabaseConnection->updateSalary(employeeId, newSalary);
}

std::map<std::string, float> EmployeeManager::vectorToMap(const std::vector<Employee> &employess) const
{
    std::map<std::string, float> res;

    for (const auto &emp: employess)
    {
        res[emp.name] = emp.salary;
    }
    return res;
}

std::map<std::string, float> EmployeeManager::getSalariesGreater(float low) const
{
    auto res = mDatabaseConnection->getSalariesRange(low);
    return vectorToMap(res);
}

std::map<std::string, float> EmployeeManager::getSalariesBetween(float low, float high) const
{
    auto res = mDatabaseConnection->getSalariesRange(low, high);
    return vectorToMap(res);
}
