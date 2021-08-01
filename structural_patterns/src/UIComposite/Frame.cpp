//
// Created by sajith on 7/31/21.
//

#include <iostream>
#include "Frame.h"

int depth{};

void Frame::Paint()
{
    if (!m_IsVisible)
    {
        return;
    }

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

}

void Frame::Add(Widget *pWidget)
{
    m_Children.push_back(pWidget);
}

void Frame::Remove(Widget *pWidget)
{
    auto del =

    m_Children.erase(del, m_Children.end());
}
