//
// Created by sajith on 3/23/21.
//

//  Small Object Optimization (SOO)


#include <iostream>
#include <cstring>

class MyString
{
    static constexpr int smallObjectSize = 16;
    size_t _size;

    union Data
    {
        char buf[smallObjectSize]; // for small     object
        char *ptr;
    } _data;


public:
    explicit MyString(const char *str) : _size(std::strlen(str))
    {
        if (_size > smallObjectSize)
        {
            _data.ptr = new char[_size];
            std::strcpy(_data.ptr, str);
        }
        else
        {
            std::strcpy(_data.buf, str);
        }
    }


    ~MyString()
    {
        if (_size > smallObjectSize)
        {
            delete[]_data.ptr;
        }
    }

    MyString(MyString &&other) : _size(other._size)
    {
        if (other._size > smallObjectSize)
        {
            _data.ptr = other._data.ptr;
            other._data.ptr = nullptr;
            other._size = 0;
        }
        else
        {
            std::strcpy(_data.buf, other._data.buf);
        }
    }

    char *data()
    {
        return (_size > smallObjectSize) ? _data.ptr : _data.buf;
    }

    size_t size() const
    {
        return _size;
    }
};


int main()
{
    MyString str1("short string");
    auto str2 = std::move(str1);

    std::cout << str2.data() << "\n";

    MyString str3("Looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooon text");
    auto str4 = std::move(str3);
    std::cout << str4.data() << '\n';
    return 0;
}