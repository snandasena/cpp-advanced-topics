//
// Created by sajith on 7/3/21.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype
{
protected:
    string prototype_name_;
    float prototype_field_;

public:
    Prototype() {}

    Prototype(string prototype_name) : prototype_name_(std::move(prototype_name))
    {

    }

    virtual ~Prototype() = default;

    virtual Prototype *Clone() const = 0;

    virtual void Method(float prototype_field)
    {
        this->prototype_field_ = prototype_field;
        cout << "Call Method from " << prototype_name_ << " with field: " << prototype_field << endl;
    }

};

class ConcretePrototype1 : public Prototype
{
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(string protype_name, float concrete_prototype_field)
            : Prototype(std::move(protype_name)), concrete_prototype_field1_(concrete_prototype_field) {}

    Prototype *Clone() const override
    {
        return new ConcretePrototype1(*this);
    }
};


class ConcretePrototype2 : public Prototype
{
private:
    float concrete_prototype_field2_;

public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field)
            : Prototype(std::move(prototype_name)), concrete_prototype_field2_(concrete_prototype_field) {}

    Prototype *Clone() const override
    {
        return new ConcretePrototype2(*this);
    }
};


class PrototypeFactory
{
private:
    std::unordered_map<Type, Prototype *, std::hash<int>> prototypes_;

public:
    PrototypeFactory()
    {
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1", 50.f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2", 60.f);
    }

    ~PrototypeFactory()
    {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    Prototype *CreatePrototype(Type type)
    {
        return prototypes_[type]->Clone();
    }

};


void ClientCode(PrototypeFactory &prototype_factory)
{
    std::cout << "Let's create a Prototype 1\n";

    Prototype *prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->Method(90);

    delete prototype;

    std::cout << "\n";
    std::cout << "Let's create a Prototype 2\n";

    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->Method(10);

    delete prototype;
}

int main()
{
    PrototypeFactory *factory = new PrototypeFactory;
    ClientCode(*factory);

    delete factory;

    return 0;
}
