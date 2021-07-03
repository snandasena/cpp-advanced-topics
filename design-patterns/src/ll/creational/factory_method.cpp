//
// Created by sajith on 7/2/21.
//


#include <iostream>
#include <cstring>

using namespace std;

// Product from which the concrete product will inherit from
class Coffee
{
protected:
    char _type[15];

public:
    Coffee()
    {

    }

    char *getType()
    {
        return _type;
    };
};


// One concrete class
class Espresso : public Coffee
{
public:
    Espresso() : Coffee()
    {
        strncpy(_type, "Espresso", 9);
        cout << "Making a cup of Espresso" << endl;
    }
};

class Cappuccino : public Coffee
{
public:

    Cappuccino() : Coffee()
    {
        strncpy(_type, "Cappuccino", 11);
        cout << "Making a cup of Cappuccino" << endl;
    }
};

class CoffeeMakerFactory
{
private:
    Coffee *_coffee;

public:
    Coffee *GetCoffee(const int &type)
    {
        switch (type)
        {
            case 1:
                return new Espresso();

            case 2:
                return new Cappuccino();
            default:
                cout << "Invalid selection\n";
                return nullptr;
        }
    }
};

int main()
{

    CoffeeMakerFactory coffeeMachine{};
    Coffee *cup;
    cup = coffeeMachine.GetCoffee(2);

    cout<<"You have asked for: "<< cup->getType()<<endl;

    return 0;
}