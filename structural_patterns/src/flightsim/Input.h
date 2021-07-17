//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_INPUT_H
#define ADVANCED_TOPICS_INPUT_H

class Input
{
public:

    virtual bool Up() = 0;

    virtual bool Down() = 0;

    virtual bool Left() = 0;

    virtual bool Right() = 0;

    virtual ~Input() = default;

};

#endif //ADVANCED_TOPICS_INPUT_H
