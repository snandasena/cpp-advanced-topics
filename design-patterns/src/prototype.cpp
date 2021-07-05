//
// Created by sajith on 7/3/21.
//

#include <iostream>
#include <string>
#include <utility>

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
};






