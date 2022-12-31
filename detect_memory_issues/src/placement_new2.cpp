//
// Created by sajith on 11/16/22.
//
#include <iostream>

using namespace std;

class String
{
private:
    int size;
    char *data;

public:
    String(int s) : size{s}, data(new char[s])
    {}

    // copy constructor
    String(const String &arg) : size{arg.size}
    {
        cout << "Calling copy constructor...\n";
        data = new char[size];
        for (int i = 0; i < size; ++i)
        {
            data[i] = arg.data[i];
        }
    }

    // copy assigment operator
    String &operator=(const String &arg)
    {
        cout << "Calling copy assigment operator\n";

        if (&arg != this)
        {
            cout << "Reallocating memory\n";
            delete[] data;
            data = new char[arg.size];
            size = arg.size;

            for (int i = 0; i < size; ++i)
            {
                data[i] = arg.data[i];
            }
        }
        return *this;
    }

    // move constructor
    String(String &&arg) noexcept
    {
        cout << "Move constructor called\n";
        data = arg.data;
        size = arg.size;

        arg.data = nullptr;
        arg.size = 0;
    }

//    // move assignment operator
//    String &operator=(String &&arg) noexcept
//    {
//        if (this != &arg)
//        {
//            delete[] data;
//            size = arg.size;
//            data = arg.data;
//
//            cout << "Move assignment operator called\n";
//            arg.data = nullptr;
//            arg.size = 0;
//        }
//        return *this;
//    }

    String &operator=(String &&arg)
    {
        cout << "Move assigment operator called\n";
        String temp(move(arg));
        swap(*this, temp);
        return *this;
    }
    ~String()
    {
        cout << "Calling destructor: " << static_cast<void *>(data) << endl;
        delete[] data;
    }

    friend void swap(String &l, String &r) noexcept;

    void print()
    {
        cout << "String with size = " << size;
        cout << ", data address = " << static_cast<void *>(data) << endl;
    }
};

inline void swap(String &l, String &r) noexcept
{
    using std::swap;
    swap(l.size, r.size);
    swap(l.data, r.data);
}

int main()
{
    String a{5};
    cout << "a: ";
    a.print();

    {
        String b{6};
        cout << "b: ";
        b.print();

        cout << "Copy construction of c from b\n";
        String c{b};
        cout << "b: ";
        b.print();
        cout << "c: ";
        c.print();

        cout << "Move construction of c from a\n";
        c = move(a);
        cout << "a: ";
        a.print();
        cout << "c: ";
        c.print();
    }
}