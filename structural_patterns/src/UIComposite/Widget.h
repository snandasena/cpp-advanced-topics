//
// Created by sajith on 7/29/21.
//

#ifndef ADVANCED_TOPICS_WIDGET_H
#define ADVANCED_TOPICS_WIDGET_H

class Widget
{
protected:
    bool m_IsVisible{true};
public:
    virtual ~Widget() = default;
    virtual void Paint() = 0;
    virtual void SetVisibility(bool visibility) = 0;
    virtual void Add(Widget *pWidget) = 0;
    virtual void Remove(Widget *pWidget) = 0;

};

#endif //ADVANCED_TOPICS_WIDGET_H
