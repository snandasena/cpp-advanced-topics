//
// Created by sajith on 7/26/22.
//

#ifndef ADVANCED_TOPICS_FRIENDS_H
#define ADVANCED_TOPICS_FRIENDS_H

#include "base.h"


class Base
{
    int x;

public:

    Base()
    {}
    Base(int i) : x{i}
    {}

    friend void func(Base &);
};

void func(Base &b)
{
    cout << b.x << endl;
    b.x = 20;
    cout << b.x << endl;
}
void test()
{
    Base b(10);
    func(b);
}

#endif //ADVANCED_TOPICS_FRIENDS_H
