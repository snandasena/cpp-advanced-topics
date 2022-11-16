//
// Created by sajith on 11/16/22.
//

#include <iostream>

using namespace std;


class Reporter
{
    int m_data;

public:

    Reporter(int x) : m_data{x}
    {
        cout << "Reporter(int)\n";
    }

    Reporter()
    {
        cout << "Reporter()\n";
    }

    ~Reporter()
    {
        cout << "~Reporter()\n";
    }


    Reporter &operator=(const Reporter &other)
    {
        cout << "operator = \n";
        m_data = other.m_data;
        return *this;
    }
};

int main()
{
    const int SIZE = 5;
//    Reporter *r = new Reporter[5]{};
    Reporter *r = static_cast<Reporter *>(operator new(SIZE * sizeof(Reporter)));

    for (int i = 0; i < SIZE; ++i)
    {
        new(r + i)Reporter{i};
    }

    for (int i = 0; i < SIZE; ++i)
    {
        r[i].~Reporter();
    }

    operator delete(r);
}