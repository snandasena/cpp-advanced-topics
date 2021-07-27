//
// Created by sajith on 7/27/21.
//

#ifndef ADVANCED_TOPICS_COMPOSITE_H
#define ADVANCED_TOPICS_COMPOSITE_H

#include <vector>
#include "Component.h"

class Composite : public Component
{
    std::vector<Component *> m_Children;

public:

    void Operation() override;
    void Add(Component *pComponent) override;
    void Remove(Component *pComponent) override;
    Component *GetChild(int index) override;
};

#endif //ADVANCED_TOPICS_COMPOSITE_H
