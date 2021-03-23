//
// Created by sajith on 3/22/21.
//

#include <iostream>
#include <utility>
#include <memory>


template<typename T>
class UniquePointer
{

public:
    UniquePointer() : ptr{nullptr} {}

    UniquePointer(T *ptr_) : ptr{ptr_} {}

    ~UniquePointer() { delete ptr; }

    template <typename... Args>
    UniquePointer(Args&&... args):ptr(new T(std::forward<Args>(args)...)){}

    UniquePointer(const UniquePointer &) = delete; // delete copy constructor
    UniquePointer(UniquePointer &&other)noexcept : ptr{other.ptr} // move constructor
    {
        other.ptr = nullptr;
    }

    UniquePointer &operator=(const UniquePointer &) = delete;// delete copy asignment operator

    UniquePointer &operator=(UniquePointer &&other)noexcept
    {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    T *get()
    {
        return ptr;
    }

    void reset()
    {
        delete ptr;
        ptr = nullptr;
    }

    T *release()
    {
        T *temp = ptr;
        delete ptr;
        return temp;
    }

    T &operator*() { return *ptr; }

    operator bool() { return ptr != nullptr; }

private:
    T *ptr;
};

class Point
{
public:
    Point(const int x_, const int y_) : x{x_}, y{y_} {}

private:
    int x, y;
};


int main()
{
    auto p = UniquePointer<Point>(new Point(5, 10));
    std::cout << std::boolalpha << ((bool) p) << '\n';
    //
    //    p.reset();
    //    std::cout << ((bool) p) << '\n';
    //

    auto p2 = std::move(p);
    std::cout << std::boolalpha << ((bool) p) << '\n';
    std::cout << std::boolalpha << ((bool) p2) << '\n';

    return 0;
}