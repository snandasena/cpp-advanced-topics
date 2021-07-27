//
// Created by sajith on 7/27/21.
//

#include <algorithm>
#include <iostream>
#include "Composite.h"


int depth{};

void Composite::Operation()
{
    ++depth;
    std::cout << "[Composite] Operation\n";
    for (const auto &pChild: m_Children)
    {
        for (int i = 0; i < depth; ++i)
        {
            std::cout << "\t";
        }
        std::cout << "|-";
        pChild->Operation();
    }
    --depth;
}

void Composite::Add(Component *pComponent)
{
    m_Children.push_back(pComponent);
}

void Composite::Remove(Component *pComponent)
{
    auto newend = remove(begin(m_Children), end(m_Children), pComponent);
    m_Children.erase(newend, m_Children.end());
}

Component *Composite::GetChild(int index)
{
    return m_Children[index];
}
