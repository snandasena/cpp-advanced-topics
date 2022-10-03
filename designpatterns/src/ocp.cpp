//
// Created by sajith on 10/1/22.
//

#include <bits/stdc++.h>

using namespace std;

enum class Color
{
    red,
    green,
    blue
};

enum class Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

template<typename T>
struct Specification
{
    virtual ~Specification() = default;

    virtual bool is_satisfied(T *item) const = 0;
};


template<typename T>
struct Filter
{
    virtual ~Filter() = default;

    virtual vector<T *> filter(const vector<T *> &items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(const vector<Product *> &products, Specification<Product> &spec) override
    {
        vector<Product *> result;
        for (const auto &ele: products)
        {
            if (spec.is_satisfied(ele))
            {
                result.push_back(ele);
            }
        }
        return result;
    }
};

template<typename T>
struct AndSpecification : Specification<T>
{
    const Specification<T> &first;
    const Specification<T> &second;

    AndSpecification(const Specification<T> &f, const Specification<T> &s) : first{f}, second{s}
    {

    }

    bool is_satisfied(T *item) const override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

template<typename T>
AndSpecification<T> operator&&(const Specification<T> &first, const Specification<T> &second)
{
    return {first, second};
}

struct ColorSpecification : Specification<Product>
{
    Color _color;

    explicit ColorSpecification(Color color) : _color{color}
    {}

    bool is_satisfied(Product *ele) const override
    {
        return _color == ele->color;
    }
};


struct SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(Size _s) : size{_s}{};

    bool is_satisfied(Product *ele) const override
    {
        return size == ele->size;
    }
};

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    const vector<Product *> products{&apple, &tree, &house};

    BetterFilter bf;
    ColorSpecification green{Color::green};

    for (auto res = bf.filter(products, green); const auto &ele: res)
    {
        cout << ele->name << " is green\n";
    }

    SizeSpecification large{Size::large};
    AndSpecification<Product> green_n_large{green, large};

    for (auto res = bf.filter(products, green_n_large); const auto &ele: res)
    {
        cout << ele->name << " is green and large\n";
    }

    return 0;
}