//
// Created by sajith on 7/27/21.
//

#ifndef ADVANCED_TOPICS_COMPONENT_H
#define ADVANCED_TOPICS_COMPONENT_H

class Component
{

public:

    virtual ~Component() = default;
    virtual void Operation() = 0;
    virtual void Add(Component *pComponent) = 0;
    virtual void Remove(Component *pComponent) = 0;
    virtual Component *GetChild(int index) = 0;
};

#endif //ADVANCED_TOPICS_COMPONENT_H
