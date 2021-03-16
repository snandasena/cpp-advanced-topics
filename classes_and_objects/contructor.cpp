//
// Created by sajith on 3/9/21.
//

#include <string>
#include <iostream>

using namespace std;

const string unk = "unknwon";
const string clone_prefix = "clone prefix";


// Interface
class Animal
{
    string _type = "";
    string _name = "";
    string _sound = "";

public:
    Animal();

    Animal(const string &type, const string &name, const string &sound);

    Animal(const Animal &);

    Animal &operator=(const Animal &);

    ~Animal();

    void Print() const;
};


// Implementation

Animal::Animal() : _type(unk), _name(unk), _sound(unk)
{
    puts("default constructor");
}


Animal::Animal(const string &type, const string &name, const string &sound) : _type(type), _name(name), _sound(sound)
{
    puts("Constructor with arguments");
}


Animal::Animal(const Animal &rhs)
{
    puts("Copy constructor");
    _name = clone_prefix + rhs._name;
    _type = rhs._type;
    _sound = rhs._sound;
}


Animal::~Animal()
{
    printf("Destructor %s the %s\n", _name.c_str(), _type.c_str());
}

void Animal::Print() const
{
    printf("%s the %s says %s\n", _name.c_str(), _type.c_str(), _sound.c_str());
}


Animal &Animal::operator=(const Animal &rhs)
{
    if (this != &rhs)
    {
        _name = clone_prefix + rhs._name;
        _type = rhs._type;
        _sound = rhs._sound;
    }

    return *this;
}


int main()
{
    Animal a;
    a.Print();

    const Animal b("Cat", "Fluffy", "Meow");
    b.Print();

    const Animal c = b;
    c.Print();

    a = c;
    a.Print();

    return 0;
}
