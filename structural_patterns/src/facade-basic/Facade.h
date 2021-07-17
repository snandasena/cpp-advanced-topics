//
// Created by sajith on 7/17/21.
//

#ifndef ADVANCED_TOPICS_FACADE_H
#define ADVANCED_TOPICS_FACADE_H

class A;

class B;

class C;

class Facade
{

    A *m_pA;
    B *m_pB;
    C *m_pC;

public:
    Facade();

    ~Facade();

    void Use();
};

#endif //ADVANCED_TOPICS_FACADE_H
