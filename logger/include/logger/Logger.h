//
// Created by sajith on 3/21/21.
//
#pragma once

#include <string>
#include <memory>

class Logger
{
public:

    Logger();

    ~Logger();

    Logger(const Logger &) = delete; // delete copy constructor

    Logger(Logger &&); // declare move constructor

    Logger &operator=(const Logger &) = delete; // delete copy operator

    Logger &operator=(Logger &&); // declare move opertator

    void log(const std::string &);

private:

    class LoggerImpl;

    std::unique_ptr<LoggerImpl> impl;
};