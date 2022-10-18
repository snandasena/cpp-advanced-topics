//
// Created by sajith on 10/19/22.
//

#pragma once

#include <map>
#include <vector>
#include <string>

#include "Employee.h"
#include "IDatabaseConnection.h"

class EmployeeManager
{
public:

    EmployeeManager(IDatabaseConnection *dbConnection);

    ~EmployeeManager();

    void setSalary(int employeeId, float newSalary);

    float getSalary(int employeeId) const;

    std::map<std::string, float> getSalariesGreater(float low) const;

    std::map<std::string, float> getSalariesBetween(float low, float high) const;

private:
    std::map<std::string, float> vectorToMap(std::vector<Employee> const &employess) const;

    IDatabaseConnection *mDatabaseConnection;
};