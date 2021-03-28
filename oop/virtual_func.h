//
// Created by sajith on 3/28/21.
//
#pragma once

#include <iostream>
#include <string_view>

class A
{
public:
    virtual std::string_view getName()
    {
        return "A";
    }
};

class B : public A
{

public:
    virtual std::string_view getName()
    {
        return "B";
    }
};


class C : public B
{

public:
    virtual std::string_view getName()
    {
        return "C";
    }
};


class D : public C
{

public:
    virtual std::string_view getName()
    {
        return "D";
    }
};





