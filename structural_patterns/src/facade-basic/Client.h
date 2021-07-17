//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_CLIENT_H
#define ADVANCED_TOPICS_CLIENT_H

#include "Facade.h"

class Client
{
    Facade *m_pF;
public:
    Client();

    ~Client();

    void Invoke();

};

#endif //ADVANCED_TOPICS_CLIENT_H
