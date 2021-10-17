//
// Created by sajith on 10/16/21.
//

#include <iostream>

using namespace std;

class Test
{
    int a, b;
public:
    Test(int a = 0, int b = 0) {} // default constructor

    void Print()
    {
        cout << "A = " << a << " B  = " << b << endl;
    }

private:
    friend void PrintTwo();
};

void PrintTwo()
{
    cout << "Hello world from friend\n";
}


class Complex
{

    int real;
    int img;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }

    int getReal() const { return real; }

    int getImag() const { return img; }

    Complex operator+(Complex x);
    friend Complex operator-(Complex x, Complex x2);
    friend ostream &operator<<(ostream &os, Complex &x);
};

Complex Complex::operator+(Complex x)
{
    Complex temp;
    temp.real = real + x.real;
    temp.img = img + x.img;
    return temp;
}

Complex operator-(Complex x1, Complex x2)
{
    Complex temp;
    temp.real = x1.real - x2.real;
    temp.img = x1.img - x2.img;
    return temp;
}


ostream &operator<<(ostream &os, Complex &x)
{
    os << "Inside the overloaded function " << x.getReal() << " " << x.getImag();
    return os;
}

class Base
{

public:

    Base()
    {
        cout << "Default of base\n";
    }

    Base(int x)
    {
        cout << "Param of base class " << x << endl;
    }
};

class Derived : public Base
{
public:

    Derived()
    {
        cout << "Default of derived\n";
    }

    Derived(int x)
    {
        cout << "Param of derived class " << x << endl;
    }

    Derived(int a, int b) : Base(a)
    {
        cout << "Param derived with base " << a<< " "<< b;
    }
};

int main()
{
    Test t;
//    t.PrintTwo();
    t.Print();

    Test t2(t);
    t2.Print();

//    Test t3(move(t));
//    t3.Print();
    PrintTwo();

    Complex c1(10, 20);
    Complex c2(20, 40);

    Complex total = c1 + c2;
    cout << total.getReal() << " " << total.getImag() << endl;
    Complex sub = c1 - c2;
    cout << sub.getReal() << " " << sub.getImag() << endl;
    cout << c1 << endl<<endl;

//    Derived d;
//    Derived d2(10);
    Derived d(10, 20);

    return 0;
}