//
// Created by sajith on 7/19/21.
//

#include "Repository.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

Repository::Repository(const std::string &repopath) : m_CurrentPath(repopath) {}

void Repository::CreateFile(const std::string &filename)
{
    auto path = m_CurrentPath;
    path /= filename;
    std::ofstream out{path};

    if (!out.is_open())
    {
        throw std::runtime_error{"Could not create file"};
    }

    std::cout << GetUser()->GetInfo() << " is creating a file\n";
    std::string filedata;
    std::cout << "[CREATE] Enter data: ";
    getline(std::cin, filedata);

    out << filedata;
    std::cout << "File created successfully!";
}

void Repository::DeleteFile(const std::string &filename)
{
    auto path = m_CurrentPath;
    path /= filename;
    if (!exists(path))
    {
        throw std::runtime_error{"File does not exists"};
    }
    std::ofstream out{path};

    if (!out.is_open())
    {
        throw std::runtime_error{"Could not create file"};
    }

    std::cout << GetUser()->GetInfo() << " is deleting a file\n";

    if (remove(path))
    {
        std::cout << "File deleted successfully\n";
    }
}

void Repository::UpdateFile(const std::string &filename)
{
    auto path = m_CurrentPath;
    path /= filename;
    if (!exists(path))
    {
        throw std::runtime_error{"File does not exists"};
    }

    std::ofstream out{path};

    if (!out.is_open())
    {
        throw std::runtime_error{"Could not create file"};
    }

    std::cout << GetUser()->GetInfo() << " is updating a file\n";
    std::string filedata;
    std::cout << "[UPDATE] Enter data: ";
    getline(std::cin, filedata);
    out << "\n##### UPDATE #####\n" << filedata;
    std::cout << "File created successfully!";
}

void Repository::ViewFile(const std::string &filename)
{
    auto path = m_CurrentPath;
    path /= filename;
    std::ifstream in{path};
    if (!in.is_open())
    {
        throw std::runtime_error{"Could not open file"};
    }

    std::cout << GetUser()->GetInfo() << " is viewing a file\n";

    std::string line;

    while (std::getline(in, line))
    {
        std::cout << line << "\n";
    }
}