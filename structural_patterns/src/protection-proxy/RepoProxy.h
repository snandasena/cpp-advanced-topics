//
// Created by sajith on 7/19/21.
//

#ifndef ADVANCED_TOPICS_REPOPROXY_H
#define ADVANCED_TOPICS_REPOPROXY_H

#include "Storage.h"
#include "Repository.h"
#include <vector>

class RepoProxy : public Storage
{
    Repository *m_pRepo;
    std::vector<std::string> m_AuthorizedRoles;

    bool IsAuthorized() const;

public:

    RepoProxy(const std::string &path);

    ~RepoProxy();

    Employee *GetUser() const;

    void SetEmployee(Employee *emp);

    void SetAuthorizedRoles(std::initializer_list<std::string> authorizedRoles);

    void CreateFile(const std::string &filename) override;

    void DeleteFile(const std::string &filename) override;

    void ViewFile(const std::string &filename) override;

    void UpdateFile(const std::string &filename) override;

};

#endif //ADVANCED_TOPICS_REPOPROXY_H
