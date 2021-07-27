//
// Created by sajith on 7/27/21.
//

#ifndef ADVANCED_TOPICS_LEAF_H
#define ADVANCED_TOPICS_LEAF_H

#include "Component.h"

class Leaf : public Component
{
public:

    void Operation() override;
    void Add(Component *pComponent) override;
    void Remove(Component *pComponent) override;
    Component *GetChild(int index) override;
};

#endif //ADVANCED_TOPICS_LEAF_H
