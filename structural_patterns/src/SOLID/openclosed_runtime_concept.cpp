//
// Created by sajith on 7/20/21.
//


#include <string>
#include <iostream>
#include <vector>
#include <memory>

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
    Wrapper(T &&speakable):ptr{std::make_unique<Model < T>>(std::forward<T>(speakable))}
    {

    }

    void speak() const
    {
        ptr->speak();
    }

private:

    class Concept
    {
    public:
        virtual ~Concept() = default;

        virtual void speak() const = 0;

    };

    template<typename T>
    class Model : public Concept
    {
    public:
        Model(T &&speakable) : m_speakable{std::move(speakable)} {};

        void speak() const override
        {
            std::cout << "Logic extended: ";
            m_speakable.speak();
        }

    private:
        T m_speakable;
    };

    std::unique_ptr<Concept> ptr;

};


void talk(const std::vector<Wrapper> &vec)
{
    for (const auto &e: vec)
    {
        std::cout << "Hello. ";
        e.speak();
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