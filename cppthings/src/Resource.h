//
// Created by sajith on 11/13/21.
//

#ifndef ADVANCED_TOPICS_RESOURCE_H
#define ADVANCED_TOPICS_RESOURCE_H

#include <string>

class Resource
{
private:
    std::string name;

public:

    Resource(std::string _name);
    ~Resource(void );

    std::string GetName() const { return name; }
};

#endif //ADVANCED_TOPICS_RESOURCE_H
