//
// Created by sajith on 7/31/21.
//

#ifndef ADVANCED_TOPICS_BUTTON_H
#define ADVANCED_TOPICS_BUTTON_H

#include "Widget.h"

class Button : public Widget
{
public:
    void Paint() override;
    void SetVisibility(bool visibility) override;
    void Add(Widget *pWidget) override;
    void Remove(Widget *pWidget) override;

};

#endif //ADVANCED_TOPICS_BUTTON_H
