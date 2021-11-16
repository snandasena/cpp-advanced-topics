//
// Created by sajith on 11/16/21.
//
#include <iostream>
#include <memory>
#include <cassert>
#include <fstream>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
using std::FILE;

struct B
{
    virtual ~B() = default;

    virtual void bar() { cout << "B::bar\n"; }
};

struct D : B
{
    D() { cout << "D::D\n"; }

    ~D() { cout << "D::~D\n"; }

    void bar() { cout << "D::bar\n"; }
};

unique_ptr<D> pass_through(unique_ptr<D> p)
{
    p->bar();
    return p; // return rvalue
}

// custom deleter
void close_file(FILE *fp)
{
    std::fclose(fp);
}

struct List
{
    struct Node
    {
        int data;
        unique_ptr<Node> next;
    };

    unique_ptr<Node> head;

    ~List()
    {
        while (head)
        {
            head = std::move(head->next);
        }
    }

    void push(int data)
    {
        head = unique_ptr<Node>(new Node{data, std::move(head)});
    }
};

int main()
{
    cout << "01: Unique ownership semantics demo\n";
    {
        auto p = make_unique<D>();
        auto q = pass_through(std::move(p));
        assert(!p);
    }

    cout << "\n02 Runtime polymorphism demo\n";
    {
        unique_ptr<B> p = make_unique<D>();
        p->bar();
    }

    cout << "\n03 Custom deleter demo\n";
    {
        using unique_file_t = unique_ptr<FILE, decltype(&close_file)>;
        unique_file_t fp(std::fopen("../demo.txt", "r"), &close_file);
        if (fp)
        {
            cout << char(std::getc(fp.get())) << "\n";
        }
    }

    cout << "\n04 Custom lambda expression deleter and exception safety demo\n";
    try
    {
        unique_ptr<D, void (*)(D *)> p(new D, [](D *ptr)
        {
            cout << "destroying from custom deleter\n";
            delete ptr;
        });
    }
    catch (std::exception &e)
    {
        cout << "Caught exception\n";
    }

    cout << "\n05 Array form of unique pointer demo\n";
    {
        unique_ptr<D[]> p(new D[3]);
    }

    cout << "\n06 Linked list demo\n";
    {
        List wall;
        for (int i = 0; i != 1'000'000; ++i)
        {
            wall.push(i);
        }
        std::cout << "1'000'000 bottles of beer on the wall...\n";
    }
    return 0;
}


