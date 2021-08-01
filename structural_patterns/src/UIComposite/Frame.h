//
// Created by sajith on 7/31/21.
//

#ifndef ADVANCED_TOPICS_FRAME_H
#define ADVANCED_TOPICS_FRAME_H

#include <vector>
#include "Widget.h"

class Frame : public Widget
{
    std::vector<Widget *> m_Children;
public:
    void Paint() override;
    void SetVisibility(bool visibility) override;
    void Add(Widget *pWidget) override;
    void Remove(Widget *pWidget) override;
};

#endif //ADVANCED_TOPICS_FRAME_H
