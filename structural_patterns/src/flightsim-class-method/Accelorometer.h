//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_ACCELOROMETER_H
#define ADVANCED_TOPICS_ACCELOROMETER_H

#include <random>

class Accelerometer
{
    std::default_random_engine m_Engine{999};

public:

    double GetHorizontalAxis();

    double GetVerticalAxis();

    virtual std::pair<int, int> Initialize();

};

#endif //ADVANCED_TOPICS_ACCELOROMETER_H
