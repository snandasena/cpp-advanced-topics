//
// Created by sajith on 3/20/21.
//

#include <iostream>
#include <memory>


struct Any
{
    struct Base
    {
    };

    template<typename T>
    struct Inner : Base
    {
        Inner(T t) : _t{std::move(t)} {}

        T _t;

        static void type() {};
    };

    constexpr Any() : ptr{nullptr}, typePtr{nullptr} {}

    template<typename T>
    constexpr Any(T &&t):
            ptr{std::make_unique<Inner<T>>(t)},
            typePtr{&Inner<T>::type}
    {

    }


    template<typename T>
    constexpr Any &operator=(T &&t)
    {
        ptr = std::make_unique<Inner<T>>(t);
        typePtr = &Inner<T>::type;

        return *this;
    }

private:

    template<typename T>
    friend T &anyCast(const Any &);

    std::unique_ptr<Base> ptr = nullptr;

    void (*typePtr)() = nullptr;
};

template<typename T>
T &anyCast(const Any &any)
{
    if (any.typePtr == &Any::Inner<T>::type)
    {
        return static_cast<Any::Inner<T> *>(any.ptr.get())->_t;
    }

    throw std::logic_error{"Bad cast!"};
}


int main()
{
    Any any(10);
    std::cout << anyCast<int>(any) << "\n";

    any = std::string{"text here"};
    std::cout << anyCast<std::string>(any) << "\n";

//    std::cout << anyCast<int >(any) << "\n"; // terminate called after throwing an instance of 'std::logic_error'
//    what():  Bad cast!

    return 0;
}