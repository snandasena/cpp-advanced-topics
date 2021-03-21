//
// Created by sajith on 3/21/21.
//

#include "logger/Logger.h"
#include <fstream>
#include <iostream>


namespace constants
    {
            static constexpr char filename[] = "Fast_MyLogs.txt";
    }

class LoggerImpl
{

public:
    LoggerImpl() : file(constants::filename) {}

    void log(const std::string &log)
    {
        std::cout << "Logging: " << log << '\n';
        file << log << '\n';
    }

private:
    std::ofstream file;
};


Logger::Logger()
{
    static_assert(sizeof(impl) >= sizeof(LoggerImpl));
    new(&impl)LoggerImpl;
}

Logger::~Logger()
{
    reinterpret_cast<LoggerImpl *>(&impl)->~LoggerImpl();
}


void Logger::log(const std::string &info)
{
    reinterpret_cast<LoggerImpl *>(&impl)->log(info);
}