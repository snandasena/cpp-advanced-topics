//
// Created by sajith on 7/19/21.
//

#ifndef ADVANCED_TOPICS_REPOSITORY_H
#define ADVANCED_TOPICS_REPOSITORY_H

#include <filesystem>
#include "Storage.h"
#include "Employee.h"

class Repository : public Storage
{

    Employee *m_pEmp;
    std::filesystem::path m_CurrentPath;

public:
    Employee *GetUser() const
    {
        return m_pEmp;
    }

    void SetEmployee(Employee *p)
    {
        m_pEmp = p;
    }

    Repository(const std::string &repopath);

    void CreateFile(const std::string &filename) override;

    void DeleteFile(const std::string &filename) override;

    void ViewFile(const std::string &filename) override;

    void UpdateFile(const std::string &filename) override;
};

#endif //ADVANCED_TOPICS_REPOSITORY_H
