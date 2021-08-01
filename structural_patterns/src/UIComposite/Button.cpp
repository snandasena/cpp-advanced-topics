//
// Created by sajith on 7/31/21.
//

#include <iostream>
#include "Button.h"

void Button::Paint()
{

    if (m_IsVisible)
    {
        std::cout << "[Button] Painting...\n";
    }

}

void Button::SetVisibility(bool visibility)
{
    std::cout << std::boolalpha;
    std::cout << "[Button] Visibility: " << visibility << "\n";
    m_IsVisible = visibility;
}

void Button::Add(Widget *pWidget)
{

}

void Button::Remove(Widget *pWidget)
{

}
