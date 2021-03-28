//
// Created by sajith on 3/28/21.
//

#ifndef ADVANCED_TOPICS_BALL_H
#define ADVANCED_TOPICS_BALL_H

#include <iostream>
#include <string>

using std::string;

class Ball
{
    string m_color;
    double m_radius;

public:
    Ball()
    {
        m_color = "black";
        m_radius = 10.0;
    }

    Ball(const string &color)
    {
        m_color = color;
        m_radius = 10.0;
    }

    Ball(double radius)
    {
        m_color = "black";
        m_radius = radius;
    }

    Ball(const string &color, double radius)
    {
        m_color = color;
        m_radius = radius;
    }

    void Print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }

};

#endif //ADVANCED_TOPICS_BALL_H
