//
// Created by sajith on 5/16/21.
//

#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size)
    {
        _size = size;
        _data = new int[size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = "
                  << _size * sizeof(int)
                  << " bytes" << std::endl;
    }

    ~MyMovableClass()
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }

    MyMovableClass(const MyMovableClass &source) // Copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }

    MyMovableClass &operator=(const MyMovableClass &sourse)
    {
        if (this == &sourse)
        {
            return *this;
        }

        delete[] _data;
        _data = new int[sourse._size];
        *_data = *sourse._data;
        _size = sourse._size;
        return *this;
    }

    MyMovableClass(MyMovableClass &&source) // movable constructor; rvalue reference
    {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }

    MyMovableClass &operator=(MyMovableClass &&source) // movable assigment operator
    {
        if (this == &source)
        {
            return *this;
        }

        delete[] _data;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;

        return *this;
    }


};


MyMovableClass createObject(int size)
{
    MyMovableClass obj(size);
    return obj;
}

int main()
{
    MyMovableClass obj1(10);
    MyMovableClass obj2(obj1);
    obj2 = obj1;
    MyMovableClass obj3 = obj1;
    MyMovableClass obj4 = createObject(10);

    obj4 = createObject(10); // call to copy assigment operator

    MyMovableClass obj5(100);
    obj5 = MyMovableClass(200); // Move assigment operator

    MyMovableClass obj6 = MyMovableClass(300); // move constructor

    return 0;
}