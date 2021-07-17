//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_KEYBOARD_H
#define ADVANCED_TOPICS_KEYBOARD_H

#include "Input.h"
#include <random>

class Keyboard : public Input
{

    std::default_random_engine m_Engine{12345};

    bool SimulateInput();

public:

    bool Up() override;

    bool Down() override;

    bool Left() override;

    bool Right() override;

};

#endif //ADVANCED_TOPICS_KEYBOARD_H
