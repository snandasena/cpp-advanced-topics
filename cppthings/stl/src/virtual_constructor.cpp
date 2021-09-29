//
// Created by sajith on 9/28/21.
//

#include "base.h"

class Dog
{
public:
    virtual Dog *clone() { return new Dog(*this); } // co-variant return type
};

class YellowDog : public Dog
{

public:
    virtual YellowDog *clone() { return new YellowDog(*this); }
};

void foo(Dog *dog)
{
    Dog *d = dog->clone();
    cout << "Play with dog...\n";

}

int main()
{
    YellowDog d;
    foo(&d);
    return 0;
}
