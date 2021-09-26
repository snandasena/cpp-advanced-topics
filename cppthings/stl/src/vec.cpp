//
// Created by sajith on 9/25/21.
//

#include "base.h"

class BigArray
{
    vector<int> v;
    mutable int accessCounter;
//    int accessCounter;

    int *v2;

public:
    int getItem(int index) const
    {
        accessCounter++;
//        const_cast<BigArray *>(this)->accessCounter++;
        return v[index];
    }

    void setV2Item(int index, int x) const
    {
        *(v2 + index) = x;
    }
};


class Dog
{
public:

    ~Dog()
    {
        cout << "Dog destroyed\n";
    }

    virtual void bark() {}
};

class YellowDog : public Dog
{
public:
    ~YellowDog()
    {
        cout << "Yellow Dog destroyed.\n";
    }
};

class DogFactory
{
public:
    static shared_ptr<Dog> createYellowDog()
    {
        return shared_ptr<Dog>(new YellowDog());
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4};
    int *p = &v[3];
    v.push_back(6);
    cout << *p << endl; // undefined behaviour
    BigArray b;

    shared_ptr<Dog> dog = DogFactory::createYellowDog();

    return 0;
}