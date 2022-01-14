//
// Created by sajith on 1/14/22.
//

#ifndef ADVANCED_TOPICS_LOGGER_H
#define ADVANCED_TOPICS_LOGGER_H

#include <iostream>
#include <fstream>
#include <mutex>
#include <memory>

namespace sdn
{

    class Logger
    {
        std::mutex mtx;
        std::ofstream of;

    public:
        explicit Logger(std::string const &path)
        {
            of.open(path);
        }

        void log(std::string const &msg)
        {
            std::lock_guard lock(mtx);
            of << msg;
        }
    };
}


#endif //ADVANCED_TOPICS_LOGGER_H
