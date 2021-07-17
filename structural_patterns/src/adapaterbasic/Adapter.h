//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_ADAPTER_H
#define ADVANCED_TOPICS_ADAPTER_H

#include "Target.h"
#include "Adaptee.h"

class Adapter : public Target,
    public Adaptee // Inheritance
{
    Adaptee m_Adaptee;

public:

    void Request() override;

};

#endif //ADVANCED_TOPICS_ADAPTER_H
