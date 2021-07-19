//
// Created by sajith on 7/19/21.
//

#include "Repository.h"
#include "Storage.h"
#include "Employee.h"
#include "RepoProxy.h"
#include <iostream>

int main()
{
    try
    {
        RepoProxy repo{R"(./)"};
        repo.SetAuthorizedRoles({"Manager", "Tech Lead"});
        Employee e1{"Umar", "Programmer"};
        Employee e2{"Ayaan", "Manager"};
        Employee e3{"Raihaan", "Tech Lead"};

        repo.SetEmployee(&e1);
//        repo.CreateFile("data.txt");

        repo.SetEmployee(&e2);
        repo.ViewFile("data.txt");

    } catch (std::exception &ex)
    {
        std::cout << "Exception:" << ex.what() << "\n";
    }

    return 0;
}