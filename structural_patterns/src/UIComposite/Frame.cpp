//
// Created by sajith on 7/31/21.
//

#include <iostream>
#include <algorithm>
#include "Frame.h"

int depth{};

void Frame::Paint()
{
    if (!m_IsVisible)
    {
        return;
    }
    std::cout << "[Frame] Painting...\n";
    ++depth;
    for (auto pChild: m_Children)
    {
        for (int i = 0; i < depth; ++i)
        {
            std::cout << "\t";
        }
        pChild->Paint();
    }
    --depth;
}

void Frame::SetVisibility(bool visibility)
{
    ++depth;
    m_IsVisible = visibility;
    std::cout << "[Frame] Changing visibility\n";
    for (auto pChild: m_Children)
    {
        for (int i = 0; i < depth; ++i)
        {
            std::cout << "\t";
        }
        pChild->SetVisibility(visibility);
    }

    --depth;
}

void Frame::Add(Widget *pWidget)
{
    m_Children.push_back(pWidget);
}

void Frame::Remove(Widget *pWidget)
{
    m_Children.erase(std::remove(m_Children.begin(), m_Children.end(), pWidget), m_Children.end());
}
