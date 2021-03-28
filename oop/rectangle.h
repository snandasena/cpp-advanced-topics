//
// Created by sajith on 3/28/21.
//

#ifndef ADVANCED_TOPICS_RECTANGLE_H
#define ADVANCED_TOPICS_RECTANGLE_H

#include <iostream>

using std::string;

class Rectange
{

private:
    double m_length{1.0};
    double m_width{1.0};

public:
    Rectange(double lenth, double width) : m_length{lenth}, m_width{width} {}

    void Print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << "\n";
    }
};


#endif //ADVANCED_TOPICS_RECTANGLE_H
