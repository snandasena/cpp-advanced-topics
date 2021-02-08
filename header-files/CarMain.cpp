#include "Car.h"

int main()
{
    Car car;
    for (int i = 0; i < 10; ++i)
    {
        bool didDrive = car.drive();
        if (!didDrive)
        {
            car.fix();
        }
    }

    return 0;
}