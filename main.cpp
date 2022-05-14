

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//class Contact
//{
//public:
//    Contact(const char *name, const char *address, const char *tel);
//
//    ~Contact();
//
//    const char *Name() const { return name; }
//
//    const char *Address() const { return address; }
//
//    const char *Tel() const { return tel; }
//
//    friend std::ostream &operator<<(std::ostream &os, Contact &c);
//
//private:
//
//    char *name;
//    char *address;
//    char *tel;
//};
//
//class ContactDir
//{
//public:
//    ContactDir(const int max_size);
//
//    ~ContactDir();
//
//    void Insert(const Contact &);
//
//    void Delete(const char *name);
//
//    Contact *Find(const char *name);
//
//    friend std::ostream &operator<<(std::ostream &, ContactDir &);
//
//private:
//    int LookUp(const char *name);
//
//    Contact **contacts;
//    int dir_size;
//    int max_size;
//};
//
//Contact::Contact(const char *name, const char *address, const char *tel)
//{
//    Contact::name = new char[strlen(name) + 1];
//    Contact::address = new char[strlen(address) + 1];
//    Contact::tel = new char[strlen(tel) + 1];
//    strcpy(Contact::name, name);
//    strcpy(Contact::address, address);
//    strcpy(Contact::tel, tel);
//}
//
//Contact::~Contact()
//{
//    delete name;
//    delete address;
//    delete tel;
//}
//
//std::ostream &operator<<(std::ostream &os, Contact &c)
//{
//    os << "( " << c.name << " , " << c.address << " , " << c.tel << " )\n";
//    return os;
//}
//
//ContactDir::ContactDir(const int mx)
//{
//    typedef Contact *ContactPtr;
//    dir_size = 0;
//    max_size = mx;
//    contacts = new ContactPtr[max_size];
//}
//
//ContactDir::~ContactDir()
//{
//    for (int i = 0; i < dir_size; ++i)
//    {
//        delete contacts[i];
//    }
//    delete[] contacts;
//}
//
//void ContactDir::Insert(const Contact &c)
//{
//    if (dir_size < max_size)
//    {
//        int idx = LookUp(c.Name());
//        if (idx > 0 && strcmp(c.Name(), contacts[idx]->Name()) == 0)
//        {
//            delete contacts[idx];
//        }
//        else
//        {
//            for (int i = dir_size; i > idx; --i)
//            {
//                contacts[i] = contacts[i - 1];
//            }
//            ++dir_size;
//        }
//        contacts[idx] = new Contact(c.Name(), c.Address(), c.Tel());
//    }
//}
//
//void ContactDir::Delete(const char *name)
//{
//    int idx = LookUp(name);
//    if (idx < dir_size)
//    {
//        delete contacts[idx];
//        --dir_size;
//        for (int i = idx; i < dir_size; ++i)
//        {
//            contacts[i] = contacts[i + 1];
//        }
//    }
//}
//
//Contact *ContactDir::Find(const char *name)
//{
//    int idx = LookUp(name);
//    return (idx < dir_size && strcmp(contacts[idx]->Name(), name) == 0) ? contacts[idx] : nullptr;
//}
//
//int ContactDir::LookUp(const char *name)
//{
//    for (int i = 0; i < dir_size; ++i)
//    {
//        if (strcmp(contacts[i]->Name(), name) == 0) return i;
//    }
//    return dir_size;
//}
//
//
//std::ostream &operator<<(std::ostream &os, ContactDir &c)
//{
//    for (int i = 0; i < c.dir_size; ++i)
//    {
//        os << *(c.contacts[i]) << '\n';
//    }
//    return os;
//}
//
//
//class SmartDir : public ContactDir
//{
//public:
//    SmartDir(const int mx) : ContactDir(mx) {}
//
//    Contact *Recent();
//
//    Contact *Find(const char *name);
//
//private:
//
//    char *recent = nullptr;
//};
//
//
//Contact *SmartDir::Recent()
//{
//    return recent == nullptr ? nullptr : ContactDir::Find(recent);
//}
//
//Contact *SmartDir::Find(const char *name)
//{
//    Contact *c = ContactDir::Find(name);
//    if (c != nullptr)
//    {
//        recent = (char *)c->Name();
//    }
//    return c;
//}

//
//class A
//{
//private:
//    int x{10};
//
//    void Fx() {};
//protected:
//    int y{20};
//
//    void Fy() {}
//
//public:
//    int z{30};
//
//    void Fz() {}
//
//public:
//
//    A()
//    {
//        printf("A called\n");
//    }
//
//    ~A()
//    {
//        printf("A deleted\n");
//    }
//};
//
//class B : public A
//{
//public:
//    B()
//    {
//        printf("%d\n", A::z);
//        printf("B called\n");
//    }
//
//    ~B()
//    {
//        printf("B deleted\n");
//    }
//};
//
//class C : protected A
//{
//public:
//    C()
//    {
//        printf("%d\n", A::z);
//        printf("C called\n");
//    }
//
//    ~C()
//    {
//        printf("C deleted\n");
//    }
//};
//
//class D : private A
//{
//
//public:
//
//
//    D()
//    {
//        printf("%d\n", A::z);
//        printf("D called");
//    }
//
//
//};

class OptionList
{
public:
    OptionList(int n);
};

class Rect;

class Window
{
public:
    Window(Rect &bounds);
};

class Menu : public OptionList, public Window
{
public:

    Menu(int n, Rect &bounds);
};


//Menu::Menu(int n, Rect &bounds) : OptionList(n), Window(bounds) {}

//class A
//{
//public:
//    A()
//    {
//        printf("From A\n");
//    }
//
//    ~A()
//    {
//        printf("A deleted\n");
//    }
//
//    void Func()
//    {
//        printf("Called func from A\n");
//    }
//};
//
//class B
//{
//public:
//
//    B()
//    {
//        printf("From B\n");
//    }
//
//    ~B()
//    {
//        printf("B deleted\n");
//    }
//
//    void Func()
//    {
//        printf("Called func from B\n");
//    }
//};
//
//
//class C : public B, public A
//{
//public:
//    C() :B(), A()
//    {
//        printf("From C\n");
//    }
//
//    ~C()
//    {
//        printf("C deleted\n");
//    }
//};


class A
{
public:
    A()
    {
        printf("A called\n");
    }
};

class B : virtual public A
{
public:
    B()
    {
        printf("B called\n");
    }
};

class C : virtual public A
{
public:
    C()
    {
        printf("C called\n");
    }
};

class D : public B, public C
{
public:
    D()
    {
        printf("D called\n");
    }
};

using ll = long long;

ll fib(ll n)
{
    if (n == 0)return 0;
    ll a = 0;
    ll b = 1;
    ll c;
    for (ll i = 2; i < n; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return a + b;
}

template<typename T>
T MAX(T &t1, T &t2)
{
    return t1 < t2 ? t2 : t1;
}

class Temp
{
    int x;
public:
    Temp(int _x) : x{_x} {};

    friend bool operator<(const Temp &t1, const Temp &t2);
};

bool operator<(const Temp &t1, const Temp &t2)
{
    return t1.x < t2.x;
}

#define CheckPtr(ptr) \
    if((ptr) !=nullptr) \
        cout<<(#ptr)<<'\n'

#define internal(var) internal##var

class AA
{
    int x;
public:
    AA() = default;

    virtual int Get();
};

class BB : public AA
{

};

class Ctor
{

};

class Box
{

public:
    Box() = default;

    Box(initializer_list<string> list, int i, int j, int k) : m_width{i}, m_height{j}, m_length{k}, contents(list) {}

    explicit Box(int i) : m_width{i}, m_height{i}, m_length{i} {}

    Box(int i, int j, int k) : m_width{i}, m_height{j}, m_length{k} {}

    Box(const Box &other) : m_width{other.m_width}, m_height{other.m_height}, m_length{other.m_length}
    {
        printf("COPY CTOR\n");
    }

    Box &operator=(const Box &other)
    {
        printf("COPY ASSIGMENT\n");
        this->m_width = other.m_width;
        this->m_height = other.m_height;
        this->m_length = other.m_length;
        this->contents = other.contents;
        return *this;
    }

    Box(Box &&other) noexcept: m_width{other.m_width}, m_height{other.m_height}, m_length{other.m_length},
                               contents(move(other.contents))
    {
        printf("MOVE CTOR\n");
    }

    Box &operator=(Box &&other) noexcept
    {
        printf("MOVE ASSIGMENT\n");
        this->m_width = other.m_width;
        this->m_height = other.m_height;
        this->m_length = other.m_length;
        this->contents = move(other.contents);
        return *this;
    }

private:

    int m_width{0};
    int m_height{0};
    int m_length{0};
    vector<string> contents;
};

class Base
{

public:
    Base()
    {
        printf("Base ctor\n");
    }

    Base(const Base &other)
    {
        printf("Base Copy ctor\n");
    }

    explicit Base(int i) : num{i}
    {
        printf("Base(int)\n");
    }

    explicit Base(char c) : letter{c}
    {
        printf("Base(char)\n");
    }

private:
    int num;
    char letter;

};

class Derived : public Base
{
public:

    using Base::Base;

private:

    int new_num{0};
};

struct Date
{
    unsigned short week_day: 3;
    unsigned short month_day: 6;
    unsigned short month: 5;
    unsigned short year: 8  ;
};

int main()
{
    Date d{1,25,12,100};

    printf("%d", d.year);

    return 0;
}
