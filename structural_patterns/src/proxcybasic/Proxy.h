//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_PROXY_H
#define ADVANCED_TOPICS_PROXY_H

#include "Subject.h"
#include "RealSubject.h"

class Proxy : public Subject
{
    RealSubject *m_pSubject{nullptr};
public:
    ~Proxy();

    void Request() override;

};

#endif //ADVANCED_TOPICS_PROXY_H
