//
// Created by sajith on 10/20/22.
//

#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
class Array
{
public:

    Array(T *array, int size) : array_{array}, size_{size}
    {}
    ~Array()
    {
        delete[] array_;
    }

    T &operator[](int index)
    {
        return array_[index];
    }

    int size() const
    {
        return size_;
    }

    friend void swap(Array &left, Array &right) noexcept
    {
        using std::swap;

        swap(left.array_, right.array_);
        swap(left.size_, right.size_);
    }

    Array &operator=(Array other) noexcept
    {
        swap(*this, other);
        return *this;
    }

    Array(const Array &other) : array_{new T[other.size_]}, size_{other.size_}
    {
        std::copy_n(other.array_, size_, array_);
    }

    Array(Array &&other) noexcept: array_{std::exchange(other.array_, nullptr)},
                                   size_{std::exchange(other.size_, 0)}
    {}

private:

    T *array_;
    int size_;

};

struct Widget
{
    int x;
    int y;

    Widget(int x_, int y_) : x{x_}, y{y_}
    {}

    Widget() = default;
};

template<typename T>
Array<T> make_array(int size)
{
    return Array(new T[size], size);
}

void TEST()
{
    auto arr = make_array<Widget>(10);
    std::cout << arr[9].x;
}

int main()
{
    TEST();
    return 0;
}