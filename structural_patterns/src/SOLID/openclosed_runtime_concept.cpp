//
// Created by sajith on 7/20/21.
//


#include <string>
#include <iostream>
#include <vector>

class Dog
{
    std::string m_name;

public:
    Dog(std::string name) : m_name(std::move(name)) {}

    void speak() const
    {
        std::cout << m_name << " barking...\n";
    }

};


class Cat
{
    std::string m_name;

public:
    Cat(std::string name) : m_name(std::move(name)) {}

    void speak() const
    {
        std::cout << m_name << " meowing...\n";
    }

};


class Wrapper
{
public:
    template<typename T>
    Wrapper(T &&speakable)
    {

    }

private:

    class Concept
    {
    public:
        virtual ~Concept() = default;

        virtual void speak() = 0;

    };
};


void talk(const std::vector<Wrapper> &vec)
{
    for (const auto &e: vec)
    {
        std::cout << "Hello. " << e.speak();
    }
}


int main()
{

    std::vector<Wrapper> vec;

    vec.push_back(Wrapper(Dog("Buddy")));
    vec.push_back(Wrapper(Cat("Tom")));

    talk(vec);

    return 0;
}