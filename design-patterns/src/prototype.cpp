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