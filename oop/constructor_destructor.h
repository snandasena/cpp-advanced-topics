//
// Created by sajith on 3/28/21.
//

#ifndef ADVANCED_TOPICS_CONSTRUCTOR_DESTRUCTOR_H
#define ADVANCED_TOPICS_CONSTRUCTOR_DESTRUCTOR_H

#include <iostream>

class Simple
{
private:
    int m_nID{};

public:
    Simple(int nID) : m_nID{nID}
    {
        std::cout << "Constructing simple: " << nID << "\n";
    }

    ~Simple()
    {
        std::cout << "Destructing simple: " << m_nID << "\n";
    }

    int getID()
    {
        return m_nID;
    }


};

#endif //ADVANCED_TOPICS_CONSTRUCTOR_DESTRUCTOR_H
