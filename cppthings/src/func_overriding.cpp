//
// Created by sajith on 10/19/21.
//

#include <iostream>

using namespace std;

class Base
{

public:

    virtual void display() =0;

    void method()
    {
        cout << "Concrete method\n";
    }
};


class Derrived : public Base
{

public:
    void display()
    {
        cout << "Derrived display func\n";
    }
};

class BasicCar
{

public:
    virtual void start()
    {
        cout << "Basic car starting...\n";
    }
};

class AdvancedCar : public BasicCar
{
public:
    void start()
    {
        cout << "Advanced car starting...\n";
    }
};

int main()
{
    Derrived d;
    Base *ptr = &d;
    d.display();
    ptr->display();

    cout << endl;

    BasicCar *pBcar = new AdvancedCar;
    pBcar->start();

    return 0;
}