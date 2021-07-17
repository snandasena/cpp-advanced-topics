//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_ACCELADATAPER_H
#define ADVANCED_TOPICS_ACCELADATAPER_H

#include "Input.h"
#include "Accelorometer.h"

class AccelAdapter : public Input
{

    Accelerometer m_Accel;

public:

    bool Up() override;

    bool Down() override;

    bool Left() override;

    bool Right() override;

};

#endif //ADVANCED_TOPICS_ACCELADATAPER_H
