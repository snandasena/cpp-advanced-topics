//
// Created by sajith on 3/21/21.
//

#include "logger/Logger.h"
#include <fstream>
#include <iostream>
#include <stdexcept>


namespace constants
    {
            static constexpr char filename[] = "MyLogs.txt";
    }

class Logger::LoggerImpl
{
public:
    LoggerImpl() : file(constants::filename) {}

    void log(const std::string &log);

private:

    std::ofstream file;
};


void Logger::LoggerImpl::log(const std::string &log)
{
    std::cout << "Logging: " << log << "\n";
    file << log << '\n';
}


Logger::Logger() : impl{std::make_unique<Logger::LoggerImpl>()} {}


Logger::~Logger() = default;


Logger::Logger(Logger &&) = default;

Logger &Logger::operator=(Logger &&) = default;


void Logger::log(const std::string &log)
{
    if (impl) impl->log(log);
    else
    {
        throw std::runtime_error{"cannot log!"};
    }
}