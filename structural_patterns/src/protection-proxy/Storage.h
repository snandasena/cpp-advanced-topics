//
// Created by sajith on 7/19/21.
//

#ifndef ADVANCED_TOPICS_STORAGE_H
#define ADVANCED_TOPICS_STORAGE_H

#include <string>

class Storage
{
public:

    virtual ~Storage() = default;

    virtual void CreateFile(const std::string &filename) = 0;

    virtual void DeleteFile(const std::string &filename) = 0;

    virtual void UpdateFile(const std::string &filename) = 0;

    virtual void ViewFile(const std::string &filename) = 0;
};

#endif //ADVANCED_TOPICS_STORAGE_H
