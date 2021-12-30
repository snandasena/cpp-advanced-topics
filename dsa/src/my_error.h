//
// Created by sajith on 12/30/21.
//

#ifndef ADVANCED_TOPICS_MY_ERROR_H
#define ADVANCED_TOPICS_MY_ERROR_H

#include <exception>
#include <string>
#include <memory>

class my_error : public std::exception
{
    std::unique_ptr<std::string> msg;

public:
    explicit my_error(std::string const &m)
    {
        msg = std::make_unique<std::string>(m);
    }

    char const *what() const noexcept override
    {
        return msg->c_str();
    }
};


#endif //ADVANCED_TOPICS_MY_ERROR_H
