//
// Created by sajith on 5/24/22.
//

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <fstream>
#include <typeinfo>

using namespace std;

//typedef vector<string>::const_iterator Line_iter;
//
//class Message
//{
//    Line_iter first;
//    Line_iter last;
//
//public:
//    Message(Line_iter p1, Line_iter p2) : first{p1}, last{p2} {}
//
//    Line_iter begin() const { return first; }
//
//    Line_iter end() const { return last; }
//};
//
//using Mess_iter = vector<Message>::const_iterator;
//
//struct Mail_file
//{
//    string name;
//    vector<string> lines;
//    vector<Message> m;
//
//    Mail_file(const string &&n);
//
//    Mess_iter begin() const { return m.begin(); }
//
//    Mess_iter end() const { return m.end(); }
//};
//
//Mail_file::Mail_file(const string &&n) : name{n}
//{
//    ifstream in{name};
//    if (!in)
//    {
//        cerr << "No " << name << '\n';
//        exit(1);
//    }
//
//    for (string s; getline(in, s);)
//    {
//        lines.push_back(s);
//    }
//
//    auto first = lines.begin();
//
//    for (auto p = lines.begin(); p != lines.end(); ++p)
//    {
//        if (*p == "____")
//        {
//            m.emplace_back(Message(first, p));
//            first = p + 1;
//        }
//    }
//}
//
//int is_prefix(const string &s, const string &p)
//{
//    int n = p.size();
//    if (string(s, 0, n) == p) return n;
//    return 0;
//}
//
//bool find_from_addr(const Message *m, string &s)
//{
//    for (const auto &x: *m)
//    {
//        if (int n = is_prefix(x, "From: "))
//        {
//            s = string(x, n);
//            return true;
//        }
//    }
//
//}
//
//class A
//{
//public:
//
//    A()
//    {
//        printf("A CALLED\n");
//    }
//
//    ~A()
//    {
//        printf("A DELETED");
//    }
//};


//class Base
//{
//public:
//    Base()
//    {
//        printf("BASE\n");
//    }
//
//    virtual     ~Base()
//    {
//        printf("~BASE\n");
//    }
//};
//
//class Derived : public Base
//{
//public:
//    Derived()
//    {
//        printf("DERIVED\n");
//    }
//
//    ~Derived()
//    {
//        printf("~DERIVED\n");
//    }
//};

//void test()
//{
//
//    Derived d;
//    Base *ptr;
//    ptr = &d;
//
//    delete ptr;
//}

//class Base
//{
//private:
//    virtual void testM() = 0;
//
//    void testM2() {}
//
//public:
//
//    virtual ~Base() = default;
//
//    virtual void memFuc() final
//    {
//        printf("This final func()\n");
//    };
//};
//
//class Derived final : public Base
//{
//
//public:
//
//    void testM() override
//    {
//        printf("Private virtual override\n");
//    }
//
//};

//void test()
//{
//    Base *bPtr;
//    Derived d;
//    bPtr = &d;
//
//    printf("%s", typeid(*bPtr).name());
//}
//
//void readFile(const string &name)
//{
//    std::ifstream input{name.c_str(), std::ios::in | std::ios::binary};
//    string line;
//    char  c;
//    if (input.is_open())
//        while (input.get(c))
//        {
//            printf("%c", c);
//        }
//
//    input.close();
//}
struct X
{
    int a;
    int b;
};

int main()
{

    const X *p;
    p = new X;
    p->a = 10;

    X *const p1 = new X;
//    p1 = new X;
    p1->a = 10;

    const X *const p2 = new X;
    p2->a = 10;
    
    return 0;
}

//0701516906