//
// Created by sajith on 3/19/21.
//


#include <iostream>

using namespace std;

class Distance
{

private:
    int meter;

    friend int addFive(Distance);

public:

    Distance() : meter(0) {}
};


int addFive(Distance d)
{
    d.meter += 5;
    return d.meter;
}


int main()
{
    Distance d;
    cout << "Distance is " << addFive(d) << "\n";

    return 0;
}