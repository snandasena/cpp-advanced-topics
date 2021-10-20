//
// Created by sajith on 10/19/21.
//


class Test
{

public:
    int a;
protected:
    int b;
private:
    int c;

    friend void func();
};

class Yours;

class My
{
private:
    int a = 10;

    friend Yours;
};


class Yours
{

public:
    My m;

    void fun()
    {
        m.a;
    }
};


void func()
{
    Test t;
    t.a;
    t.b;
    t.c;
}