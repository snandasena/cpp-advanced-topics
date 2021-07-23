//
// Created by sajith on 7/22/21.
//

#include <iostream>

using namespace std;

template<typename SpecificAnimal>
struct Animal
{
    void Who()
    {
        specificAnimal().Who();
    }

private:
    SpecificAnimal &specificAnimal()
    {
        return *static_cast<SpecificAnimal *>(this);
    }
};

struct Dog : Animal<Dog>
{
    void Who()
    {
        cout << "Dog\n";
    }
};

struct Cat : Animal<Cat>
{
    void Who()
    {
        cout << "Cat\n";
    }
};

template<typename SpecificAnimal>
void WhoAmI(Animal<SpecificAnimal> &animal)
{
    animal.Who();
}

int main()
{
    Dog d;
    WhoAmI(d);

    Cat c;
    WhoAmI(c);

    return 0;
}