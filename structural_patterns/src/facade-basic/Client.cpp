//
// Created by sajith on 7/17/21.
//

#include "Client.h"

Client::Client()
{
    m_pF = new Facade{};
}

Client::~Client()
{
    delete m_pF;
}

void Client::Invoke()
{
    m_pF->Use();
}
