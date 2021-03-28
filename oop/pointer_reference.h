//
// Created by sajith on 3/28/21.
//

#pragma once

#include <iostream>
#include <string_view>
#include <string>

using std::string;

class Base
{
protected:
    int m_value;

public:

    Base(int value) : m_value{value} {}

    std::string_view getName() const
    {
        return "Base";
    }

    int getValue() const
    {
        return m_value;
    }
};

class Derived : public Base
{
public:

    Derived(int value) : Base{value}
    {

    }

    std::string_view getName() const
    {
        return "Derived";
    }

    int getValueDouble() const
    {
        return m_value * 2;
    }
};


