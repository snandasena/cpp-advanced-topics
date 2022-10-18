//
// Created by sajith on 10/19/22.
//

#pragma once

#include <string>
#include <vector>

#include "Employee.h"


class IDatabaseConnection
{
public:
    IDatabaseConnection(const std::string &&serverAddress);

    virtual ~IDatabaseConnection() = default;

    virtual float getSalary(int id) const = 0;

    virtual void updateSalary(int id, float newSalary) = 0;

    virtual std::vector<Employee> getSalariesRange(float low) = 0;

    virtual std::vector<Employee> getSalariesRange(float low, float high) = 0;

    virtual void connect();

    virtual void disconnect();

protected:
    std::string mServerAddress;
};

