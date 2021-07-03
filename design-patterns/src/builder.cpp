//
// Created by sajith on 7/3/21.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product1
{
public:
    vector<string> parts_;

    void ListPats()
    {
        cout << "Product parts: ";
        for (size_t i = 0; i < parts_.size(); ++i)
        {
            if (parts_[i] == parts_.back())
            {
                cout << parts_[i];
            } else
            {
                cout << parts_[i] << ", ";
            }
        }
        cout << "\n\n";
    }
};

class Builder
{
public:
    virtual ~Builder() = default;

    virtual void ProductA() const = 0;

    virtual void ProductB() const = 0;

    virtual void ProductC() const = 0;
};

class ConcreteBuilder1 : public Builder
{
private:
    Product1 *product;

public:

    ConcreteBuilder1()
    {
        this->Reset();
    }

    ~ConcreteBuilder1()
    {
        delete product;
    }

    void Reset()
    {
        product = new Product1();
    }

    void ProductA() const override
    {
        this->product->parts_.emplace_back("PartA1");
    }

    void ProductB() const override
    {
        this->product->parts_.emplace_back("PartB1");
    }

    void ProductC() const override
    {
        this->product->parts_.emplace_back("PartC1");
    }

    Product1 *GetProduct()
    {
        Product1 *result = this->product;
        this->Reset();
        return result;
    }
};


class Director
{
private:
    Builder *_builder;

public:
    void set_builder(Builder *builder)
    {
        this->_builder = builder;
    }

    void BuildMinimalViableProduct()
    {
        this->_builder->ProductA();
    }

    void BuildFullFeaturedProduct()
    {
        this->_builder->ProductA();
        this->_builder->ProductB();
        this->_builder->ProductC();
    }
};


void ClientCode(Director &director)
{
    ConcreteBuilder1 *builder1 = new ConcreteBuilder1();
    director.set_builder(builder1);

    cout << "Standard basic product:\n";
    director.BuildMinimalViableProduct();

    Product1 *p = builder1->GetProduct();
    p->ListPats();
    delete p;

    cout << "Standard full featured product:\n";
    director.BuildFullFeaturedProduct();

    p = builder1->GetProduct();
    p->ListPats();
    delete p;

    cout << "Custom product:\n";
    builder1->ProductA();
    builder1->ProductC();
    p = builder1->GetProduct();
    p->ListPats();
    delete p;

    delete builder1;
}


int main()
{
    Director *director = new Director();
    ClientCode(*director);

    delete director;

    return 0;
}


