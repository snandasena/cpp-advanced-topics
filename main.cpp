

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <variant>

#define ENDL '\n'
#define LOG(x) std::cout<<x
#define LOGL(x) std::cout<<x<<'\n'

//using namespace std;

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
//class Base1
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
//    Base1()
//    {
//        printf("Base1 called\n");
//    }
//
//    Base1ase1()
//    {
//        printf("Base1 deleted\n");
//    }
//};
//
//class B : public Base1
//{
//public:
//    B()
//    {
//        printf("%d\n", Base1::z);
//        printf("B called\n");
//    }
//
//    ~B()
//    {
//        printf("B deleted\n");
//    }
//};
//
//class C : protected Base1
//{
//public:
//    C()
//    {
//        printf("%d\n", Base1::z);
//        printf("C called\n");
//    }
//
//    ~C()
//    {
//        printf("C deleted\n");
//    }
//};
//
//class D : private Base1
//{
//
//public:
//
//
//    D()
//    {
//        printf("%d\n", Base1::z);
//        printf("D called");
//    }
//
//
//};

//class OptionList
//{
//public:
//    OptionList(int n);
//};
//
//class Rect;
//
//class Window
//{
//public:
//    Window(Rect &bounds);
//};
//
//class Menu : public OptionList, public Window
//{
//public:
//
//    Menu(int n, Rect &bounds);
//};


//Menu::Menu(int n, Rect &bounds) : OptionList(n), Window(bounds) {}

//class Base1
//{
//public:
//    Base1()
//    {
//        printf("From Base1\n");
//    }
//
//    Base1ase1()
//    {
//        printf("Base1 deleted\n");
//    }
//
//    void Func()
//    {
//        printf("Called func from Base1\n");
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
//class C : public B, public Base1
//{
//public:
//    C() :B(), Base1()
//    {
//        printf("From C\n");
//    }
//
//    ~C()
//    {
//        printf("C deleted\n");
//    }
//};

//
//class Base1
//{
//public:
//    Base1()
//    {
//        printf("Base1 called\n");
//    }
//};
//
//class B : virtual public Base1
//{
//public:
//    B()
//    {
//        printf("B called\n");
//    }
//};
//
//class C : virtual public Base1
//{
//public:
//    C()
//    {
//        printf("C called\n");
//    }
//};
//
//class D : public B, public C
//{
//public:
//    D()
//    {
//        printf("D called\n");
//    }
//};
//
//using ll = long long;
//
//ll fib(ll n)
//{
//    if (n == 0)return 0;
//    ll a = 0;
//    ll b = 1;
//    ll c;
//    for (ll i = 2; i < n; ++i)
//    {
//        c = a + b;
//        a = b;
//        b = c;
//    }
//    return a + b;
//}
//
//template<typename T>
//T MAX(T &t1, T &t2)
//{
//    return t1 < t2 ? t2 : t1;
//}
//
//class Temp
//{
//    int x;
//public:
//    Temp(int _x) : x{_x} {};
//
//    friend bool operator<(const Temp &t1, const Temp &t2);
//};
//
//bool operator<(const Temp &t1, const Temp &t2)
//{
//    return t1.x < t2.x;
//}
//
//#define CheckPtr(ptr) \
//    if((ptr) !=nullptr) \
//        cout<<(#ptr)<<'\n'
//
//#define internal(var) internal##var
//
//class AA
//{
//    int x;
//public:
//    AA() = default;
//
//    virtual int Get();
//};
//
//class BB : public AA
//{
//
//};
//
//class Ctor
//{
//
//};
//
//class Box
//{
//
//public:
//    Box() = default;
//
//    Box(initializer_list<string> list, int i, int j, int k) : m_width{i}, m_height{j}, m_length{k}, contents(list) {}
//
//    explicit Box(int i) : m_width{i}, m_height{i}, m_length{i} {}
//
//    Box(int i, int j, int k) : m_width{i}, m_height{j}, m_length{k} {}
//
//    Box(const Box &other) : m_width{other.m_width}, m_height{other.m_height}, m_length{other.m_length}
//    {
//        printf("COPY CTOR\n");
//    }
//
//    Box &operator=(const Box &other)
//    {
//        printf("COPY ASSIGMENT\n");
//        this->m_width = other.m_width;
//        this->m_height = other.m_height;
//        this->m_length = other.m_length;
//        this->contents = other.contents;
//        return *this;
//    }
//
//    Box(Box &&other) noexcept: m_width{other.m_width}, m_height{other.m_height}, m_length{other.m_length},
//                               contents(move(other.contents))
//    {
//        printf("MOVE CTOR\n");
//    }
//
//    Box &operator=(Box &&other) noexcept
//    {
//        printf("MOVE ASSIGMENT\n");
//        this->m_width = other.m_width;
//        this->m_height = other.m_height;
//        this->m_length = other.m_length;
//        this->contents = move(other.contents);
//        return *this;
//    }
//
//private:
//
//    int m_width{0};
//    int m_height{0};
//    int m_length{0};
//    vector<string> contents;
//};
//
//class Base
//{
//
//public:
//    Base()
//    {
//        printf("Base ctor\n");
//    }
//
//    Base(const Base &other)
//    {
//        printf("Base Copy ctor\n");
//    }
//
//    explicit Base(int i) : num{i}
//    {
//        printf("Base(int)\n");
//    }
//
//    explicit Base(char c) : letter{c}
//    {
//        printf("Base(char)\n");
//    }
//
//private:
//    int num;
//    char letter;
//
//};
//
//class Derived : public Base
//{
//public:
//
//    using Base::Base;
//
//private:
//
//    int new_num{0};
//};
//
//struct Date
//{
//    unsigned short week_day: 3;
//    unsigned short month_day: 6;
//    unsigned short month: 5;
//    unsigned short year: 8;
//};
//
//class ShallowCopy
//{
//    int x;
//    int y;
//    int z;
//    int *ptr;
//
//public:
//    ShallowCopy(int _x, int _y, int _z, int vptr) : x{_x}, y{_y}, z{_z}, ptr{new int{vptr}} {}
//
//    void SetData(int _x, int _y, int _z, int vptr)
//    {
//        x = _x;
//        y = _y;
//        z = _z;
//        *ptr = vptr;
//    }
//
//    void ShowData()
//    {
//        printf("(%d, %d, %d, (%d, %p))\n", x, y, z, *ptr, ptr);
//    }
//
//    ~ShallowCopy()
//    {
//        delete ptr;
//    }
//};
//
//class DeepCopy
//{
//    int x{0};
//    int y{0};
//    int *ptr{nullptr};
//
//public:
//    DeepCopy() = default;
//
//    DeepCopy(int _x, int _y, int vptr) : x{_x}, y{_y}, ptr{new int{vptr}} {}
//
//    DeepCopy(const DeepCopy &other) : x{other.x}, y{other.y}, ptr{new int{*other.ptr}} {}
//
//    DeepCopy &operator=(const DeepCopy &other)
//    {
//        this->x = other.x;
//        this->y = other.y;
//        this->ptr = new int{*other.ptr};
//        return *this;
//    }
//
//    void ShwData()
//    {
//        printf("(%d, %d, (%d, %p))\n", x, y, *ptr, ptr);
//    }
//
//    void SetData(int _x, int _y, int vptr)
//    {
//        x = _x;
//        y = _y;
//        *ptr = vptr;
//    }
//
//    ~DeepCopy()
//    {
//        delete ptr;
//    }
//};
//
//void CopyTest()
//{
//    printf("Shallow Copy Started\n");
//    ShallowCopy sc1{1, 2, 3, 4};
//    sc1.ShowData();
//
//    ShallowCopy sc2 = sc1;
//    sc2.ShowData();
//
//    sc2.SetData(4, 5, 6, 7);
//    sc2.ShowData();
//    sc1.ShowData();
//
//    printf("Shallow Copy Finished\n\n");
//
//    printf("Deep Copy Started\n");
//    DeepCopy dc1{1, 2, 3};
//    dc1.ShwData();
//
//    DeepCopy dc2 = dc1;
//    dc2.ShwData();
//
//    dc2.SetData(4, 5, 6);
//    dc2.ShwData();
//    dc1.ShwData();
//
//    printf("Deep Copy Finished\n");
//    DeepCopy dc3;
//
//    dc3 = dc2;
//    dc3.ShwData();
//    dc3.SetData(7, 8, 9);
//    dc3.ShwData();
//    dc2.ShwData();
//}
//
//struct Link
//{
//    string value;
//    Link *prev;
//    Link *succ;
//
//    Link(const string &&v, Link *p = nullptr, Link *s = nullptr) : value{v}, prev{p}, succ{s} {}
//};
//
//
//Link *Insert(Link *p, Link *n)
//{
//    if (n == nullptr) return p;
//    if (p == nullptr) return n;
//
//    n->succ = p;
//    if (p->prev) p->prev->succ = n;
//    n->prev = p->prev;
//    p->prev = n;
//    return n;
//}
//
//void ListTest()
//{
//    Link *norse_gods = new Link{"Thor", nullptr, nullptr};
//    norse_gods = Insert(norse_gods, new Link{"Odin"});
//    norse_gods = Insert(norse_gods, new Link{"Freia"});
//    printf("");
//}
//
//class Vector
//{
//    size_t sz;
//    double *elem;
//
//public:
//    Vector(size_t s) : sz{s}, elem{new double[sz]}
//    {
//        for (size_t i = 0; i < sz; ++i)
//        {
//            elem[i] = 0.0;
//        }
//    }
//
//    Vector(initializer_list<double> lst) : sz{lst.size()}, elem{new double[sz]}
//    {
//        copy(lst.begin(), lst.end(), elem);
//    }
//
//    Vector(const Vector &arg) : sz{arg.sz}, elem{new double[sz]}
//    {
//        copy(arg.elem, arg.elem + sz, elem);
//    }
//
//    Vector &operator=(const Vector &other)
//    {
//        if (this != &other)
//        {
//            double *temp = new double[other.sz];
//            copy(other.elem, other.elem + other.sz, temp);
//            delete[] elem;
//            elem = temp;
//            sz = other.sz;
//        }
//        return *this;
//    }
//
//    Vector(Vector &&other) noexcept: sz{other.sz}, elem{other.elem}
//    {
//        other.sz = 0;
//        other.elem = nullptr;
//    }
//
//    Vector &operator=(Vector &&other)
//    {
//        if (this != &other)
//        {
//            delete[] elem;
//            elem = other.elem;
//            sz = other.sz;
//            other.elem = nullptr;
//            other.sz = 0;
//        }
//
//        return *this;
//    }
//
//    double &operator[](int n)
//    {
//        if (n >= sz) throw -1;
//        return elem[n];
//    }
//
//    double operator[](int n) const
//    {
//        return elem[n];
//    }
//
//    void Set(size_t idx, double val)
//    {
//        if (idx >= sz) throw -1;
//        elem[idx] = val;
//    }
//
//    double Get(size_t idx)
//    {
//        if (idx >= sz) throw -1;
//        return elem[idx];
//    }
//
//    ~Vector()
//    {
//        delete[] elem;
//    }
//
//};
//
//void VectorTest()
//{
//    Vector v{1.2, 2.3, 3.4, 4.5};
//    Vector v2 = {2.2, 3.3, 4.4, 5.5};
//
//    Vector v3 = v2;
//    printf("%f\n", v3.Get(0));
//
//    v3 = v;
//    printf("%f\n", v3[1]);
//    v3[1] = 10.0;
//    printf("%f\n", v3[1]);
//
//    const Vector v4 = v2;
//    double ele = v4[1];
//    printf("%f\n", ele);
//}
//
//
//bool is_palindrome(const char *first, const char *last)
//{
//    if (first < last)
//    {
//        if (*first != *last) return false;
//        return is_palindrome(first + 1, last - 1);
//    }
//    return true;
//}
//
//class AAA
//{
//public:
//    AAA()
//    {
//        printf("AAA CALLED\n");
//    }
//
//    ~AAA()
//    {
//        printf("AAA DELETED\n");
//    }
//};
//
//
//template<typename T, int N>
//struct Array
//{
//    T elem[N];
//
//    T &operator[](int n);
//
//    const T &operator[](int n) const;
//
//    const T *data() const { return elem; }
//
//    int size() const { return N; }
//};
//
//template<typename T, int N>
//void fill(Array<T, N> &b, const T &val)
//{
//    for (int i = 0; i < N; ++i)
//    {
//        b[i] = val;
//    }
//}
//
//void ArrayTest()
//{
//    Array<char, 1024> buf;
//    Array<int, 10> b2;
//
//    fill(buf, 'x');
//    fill(b2, 10);
//}

//
//class Base1
//{
//    string *str;
//public:
//    Base1(const string &s) : str{new string{s}}
//    {
//        printf("Base1 CALLED\n");
//    }
//
//    Base1ase1()
//    {
//        printf("Base1 DELETED\n");
//        delete str;
//    }
//};
//
//void OutputStreamTest()
//{
//    vector<Base1> *v = new vector<Base1>(10, Base1("Hello"));
//}

//
//template<typename Iterator>
//Iterator high(Iterator first, Iterator last)
//{
//    Iterator val = first;
//    for (auto itr = first; itr != last; ++itr)
//    {
//        if (*val < *itr) val = itr;
//    }
//    return val;
//}
//
//void OutputStreamTest()
//{
//
//    vector<int> v{1, 3, 4, 2, 6, 7, 9, 20, 0};
//    int arr[] = {1, 3, 4, 2, 6, 7, 9, 20, 0};
//    auto res = high(arr, arr+9);
//
//    printf("%d", *res);
//}


namespace cpp_practice
{

    template<typename Elem>
    struct Link
    {
        Link *prev;
        Link *succ;
        Elem val;
    };

    template<typename Elem>
    class List
    {
    public:
        class Iterator;

        Iterator begin();

        Iterator end();

        Iterator insert(Iterator p, const Elem &v);

        Iterator erase(Iterator p);

        void push_back(const Elem &v);

        void push_front(const Elem &v);

        void pop_back();

        void pop_front();

        Elem &front();

        Elem &back();
    };

    template<typename Elem>
    class List<Elem>::Iterator
    {
        Link<Elem> *curr;

        Iterator(Link<Elem> *p) : curr{p} {}

        Iterator &operator++()
        {
            curr = curr->succ;
            return *this;
        }

        Iterator &operator--()
        {
            curr = curr->prev;
            return *this;
        }

        Elem &operator*()
        {
            return curr->val;
        }

        bool operator==(const Iterator &b)
        {
            return curr == b.curr;
        }

        bool operator!=(const Iterator &b)
        {
            return curr != b.curr;
        }
    };

    template<typename T>
    class vector
    {
    public:
        using size_type = unsigned long;
        using value_type = T;
        using iterator = T *;
        using const_iterator = const T *;

        iterator begin();

        const_iterator begin() const;

        iterator end();

        const_iterator end() const;

        size_type size();

    };
}

//void OutputStreamTest()
//{
//    cpp_practice::vector<int> v;
//    cpp_practice::vector<int>::iterator itr = std::find(v.begin(), v.end(), 34);
//
//}

class Base1
{
public:

    virtual inline void fun()
    {
        printf("Base1\n");
    }

    virtual ~Base1() = default;
};

class B : public Base1
{
public:

    void fun() override
    {
        printf("B\n");
    }
};

int &f()
{
    static int x = 10;
    return x;
}

class Test
{
    static int a;
    int b;
};

int Test::a;

class calculate
{
    int x;
    int y;

public:
    void val(int, int);

    int sum()
    {
        return x + y;
    }
};

void calculate::val(int a, int b)
{
    x = a;
    y = b;
}

struct ConstExprTest
{
    static constexpr double PI = 3.14;
};

void tests()
{
    const ConstExprTest ct1;
    printf("%0.2f\n", ConstExprTest::PI);
}


template<typename First, typename... Args>
auto sum(const First first, const Args ... args)
{
    const auto values = {first, args...};
    return std::accumulate(values.begin(), values.end(), First{0});
}
//
//int main()
//{
//    auto res = sum(1, 2, 3, 4, 5);
//    std::cout << res << '\n';
//
//    auto res2 = sum(1.2, 2.3, 3.4);
//    std::cout << res2;
//    return 0;
//}

void func()
{
    int x = 10;
    auto f = [x]() mutable
    {
        x = 100;
    };

    f();
    std::cout << x << '\n';
}

//int main()
//{
//    func();
//    return 0;
//}


long long operator "" _C(unsigned long long temp)
{
    return std::llround(temp * 1.8 + 32);
}


//int main()
//{
//    auto temp = 23_C;
//    std::cout << temp << '\n';
//    return 0;
//}

namespace Programme
{
    namespace version1
    {
        int getVersion()
        {
            return 1;
        }

        bool isFirstVersion()
        {
            return true;
        }
    }

    inline namespace version2
    {
        int getVersion()
        {
            return 2;
        }
    }
}

//int main()
//{
//    auto version = Programme::getVersion();
//    std::cout << version << '\n';
//
////    auto first_version = Programme::isFirstVersion(); ERROR
//    return 0;
//}


void func_print(const std::initializer_list<int> &vals)
{
    for (const auto &ele: vals)
    {
        std::cout << ele << '\t';
    }

    std::cout << '\n';
}

template<typename Func, typename ... T>
void func_var(const Func &function, const T &... vals)
{
    const auto packs = {vals...};
    function(packs);
}

void call_func_var()
{
    func_var(func_print, 1, 2, 3, 4, 5, 5, 6, 6);
}


//int main()
//{
//    call_func_var();
//    return 0;
//}

constexpr int square(int x)
{
    return x * x;
}

//int main()
//{
//    auto ans = square(10);
//    std::cout<<ans<<'\n';
//}



struct Bar
{
};

struct Foo
{
    Bar getBar() &
    {
        std::cout << "Bar getBar() &\n";
        return bar;
    }

    Bar getBar() const &
    {
        std::cout << "Bar getBar() const &\n";
        return bar;
    }

    Bar getBar() &&
    {
        std::cout << "Bar getBar() &&\n";

        return std::move(bar);
    }

private:
    Bar bar;
};


constexpr int get(int param)
{
    if (param == 10)
    {
        return 10;
    }
    return 3 * 4;
}


void ref_qualifier_test()
{
    Foo foo;
    auto res = foo.getBar();

    const Foo fooo;
    auto resFoo = fooo.getBar();
    Foo{}.getBar();

    auto ress = std::move(foo);
    ress.getBar();
}

//int main()
//{
//    ref_qualifier_test();
//    return 0;
//}



struct MyObj
{
    int val{123};

    auto getValueCopy()
    {
        return [*this]()
        {
            return val;
        };
    }

    auto getValueByRef()
    {
        return [this]()
        {
            return val;
        };
    }
};

void lambda_this_test()
{

    MyObj obj;
    auto copy = obj.getValueCopy();
    std::cout << copy() << '\n';

    auto ref = obj.getValueByRef();
    LOG(ref()) << ENDL;

    obj.val = 1000;
    LOG(ref()) << ENDL;
    LOG(copy()) << ENDL;
}

//int main()
//{
//    lambda_this_test();
//    return 0;
//}
//



void variant_test()
{
    std::variant<int, char> v{10};
    auto val = std::get<int>(v);
    LOG(val) << ENDL;

    v = 'A';
    auto ch = std::get<char>(v);
    LOG(ch) << ENDL;
}

//int main()
//{
//    variant_test();
//    return 0;
//}



void weak_ptr_test()
{
    std::shared_ptr<int> iPtr = std::make_shared<int>(10);
    std::weak_ptr<int> wPtr(iPtr);

    LOG("weak_ptr use count: ");
    LOG(wPtr.use_count()) << ENDL;

    LOG("shared_ptr use count: ");
    LOG(iPtr.use_count()) << ENDL;

    LOG("weak_ptr expired: ");
    LOG(wPtr.expired()) << ENDL;

    if (std::shared_ptr<int> sPtr = wPtr.lock())
    {
        LOG("*sPtr: ");
        LOG(*iPtr) << ENDL;

        LOG("shared_ptr use count: ");
        LOG(sPtr.use_count()) << ENDL;
    } else
    {
        LOG("Don't get the resource\n");
    }

    wPtr.reset();

    if (std::shared_ptr<int> sPtr = wPtr.lock())
    {
        LOG("*sPtr: ");
        LOG(*iPtr) << ENDL;

        LOG("shared_ptr use count: ");
        LOG(sPtr.use_count()) << ENDL;
    } else
    {
        LOG("shared_ptr use count: ");
        LOG(sPtr.use_count()) << ENDL;
        LOG("Don't get the resource\n");
    }
}

//int main()
//{
//    weak_ptr_test();
//    return 0;
//}
//

struct Son;
struct Daughter;

struct Mother
{
    ~Mother()
    {
        LOG("Mother gone\n");
    }

    void setSon(const std::shared_ptr<Son> s)
    {
        son = s;
    }

    void setDaughter(const std::shared_ptr<Daughter> d)
    {
        daughter = d;
    }

    std::weak_ptr<Son> son;
    std::weak_ptr<Daughter> daughter;
};


struct Son
{
    Son(std::shared_ptr<Mother> m) : mother{m} {};

    ~Son()
    {
        LOG("Son gone\n");
    }

    std::shared_ptr<Mother> mother;
};

struct Daughter
{
    Daughter(std::shared_ptr<Mother> m) : mother{m} {};

    ~Daughter()
    {
        LOG("Daughter gone\n");
    }

    std::shared_ptr<Mother> mother;
};


void weak_ptr_api_test()
{
    std::shared_ptr<Mother> mother = std::make_shared<Mother>();
    std::shared_ptr<Son> son = std::make_shared<Son>(mother);
    std::shared_ptr<Daughter> daughter = std::make_shared<Daughter>(mother);

    mother->setSon(son);
    mother->setDaughter(daughter);
}

void unique_pass_as_arg(std::unique_ptr<int> ptr)
{
    LOG(*ptr);
    exit(0);
}

void TEST_1()
{
    weak_ptr_api_test();

    auto ptr = std::make_unique<int>(10);
    unique_pass_as_arg(std::move(ptr));

    LOG(*ptr);
}


template<typename T>
T max_t(T a, T b)
{
    return a > b ? a : b;
}


int max_t(int a, int b)
{
    return 10;
}

void TEST()
{
    LOGL(max_t(10, 20));

    LOGL(max_t("abs", "abd"));
}

void SomeRandomStuffs()
{
    std::list<int> l;
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);

    LOGL(l.front());
    l.pop_back();
    LOGL(l.back());
}

int main()
{
//    int *ptr = nullptr;
//    int x = *ptr;
//    LOG(x);
//
    volatile unsigned x = 1;
    volatile unsigned y = 33;
    volatile unsigned res = x<<y;
    LOG(res);
    return 0;

}











































