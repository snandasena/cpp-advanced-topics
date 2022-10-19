//
// Created by sajith on 10/19/22.
//

#include <iostream>

#include "IDatabaseConnection.h"

IDatabaseConnection::IDatabaseConnection(const std::string &serverAddress) : mServerAddress{serverAddress}
{
}

void IDatabaseConnection::connect()
{
    std::cout << "Connecting to the database server " << mServerAddress << '\n';
}

void IDatabaseConnection::disconnect()
{
    std::cout << "Disconnecting from the database...\n";
}