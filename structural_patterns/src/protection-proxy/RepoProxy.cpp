//
// Created by sajith on 7/19/21.
//

#include <algorithm>
#include <iostream>
#include "RepoProxy.h"


RepoProxy::RepoProxy(const std::string &path) : m_pRepo{new Repository{path}}
{

}

RepoProxy::~RepoProxy()
{
    delete m_pRepo;
}


void RepoProxy::SetAuthorizedRoles(std::initializer_list<std::string> authorizedRoles)
{
    m_AuthorizedRoles.assign(authorizedRoles);
}

Employee *RepoProxy::GetUser() const
{
    return m_pRepo->GetUser();
}

void RepoProxy::SetEmployee(Employee *emp)
{
    m_pRepo->SetEmployee(emp);
}


bool RepoProxy::IsAuthorized() const
{
    if (m_AuthorizedRoles.empty())
    {
        throw std::runtime_error{"Authorized roles are not set"};
    }

    return std::any_of(m_AuthorizedRoles.begin(), m_AuthorizedRoles.end(), [this](const std::string &role)
    {
        return GetUser()->GetRole() == role;
    });
}

void RepoProxy::CreateFile(const std::string &filename)
{
    if (IsAuthorized())
    {
        m_pRepo->CreateFile(filename);
    } else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to create a file\n";
    }
}

void RepoProxy::DeleteFile(const std::string &filename)
{
    if (IsAuthorized())
    {
        m_pRepo->DeleteFile(filename);
    } else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to delete a file\n";
    }

}

void RepoProxy::UpdateFile(const std::string &filename)
{
    if (IsAuthorized())
    {
        m_pRepo->UpdateFile(filename);
    } else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to update a file\n";
    }
}

void RepoProxy::ViewFile(const std::string &filename)
{
    if (IsAuthorized())
    {
        m_pRepo->ViewFile(filename);
    } else
    {
        std::cout << GetUser()->GetInfo() << " is not authorized to view a file\n";
    }
}
