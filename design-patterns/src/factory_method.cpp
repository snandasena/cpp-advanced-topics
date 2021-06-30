//
// Created by sajith on 6/30/21.
//

#include <string>
#include <iostream>


// server code

// Interface
class Product
{

public:
    virtual ~Product() = default;

    virtual std::string Operation() const = 0;
};

// concrete implementation
class ConcreteProduct1 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the concrete product1}";
    }
};


// concrete implementation
class ConcreteProduct2 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Result of the concrete product2}";
    }
};

// Abstract factory
class Creator
{
public:

    virtual ~Creator() = default;

    virtual Product *FactoryMethod() const = 0;

    std::string SomeOperation() const
    {
        Product *product = this->FactoryMethod();
        std::string result = "Creator: the same creator code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

// extending abstract factory and create a concrete implementation
class ConcreteCreator1 : public Creator
{
public:

    Product *FactoryMethod() const override
    {
        return new ConcreteProduct1();
    }
};

class ConcreteCreator2 : public Creator
{

public:
    Product *FactoryMethod() const override
    {
        return new ConcreteProduct2();
    }
};


// client code

void ClientCode(const Creator &creator)
{
    std::cout << "Client: I'm not aware of the creator's class, but it still works\n"
              << creator.SomeOperation() << std::endl;
}


int main()
{
    std::cout << "App: Launched with the concrete creator1.\n";
    Creator *creator1 = new ConcreteCreator1();
    ClientCode(*creator1);

    std::cout << std::endl;
    std::cout << "App: Launched with the concrete creator2.\n";
    Creator *creator2 = new ConcreteCreator2();
    ClientCode(*creator2);

    delete creator1;
    delete creator2;

    return 0;
}