

#include <cstdio>
#include <iostream>
#include <cstring>
#include <functional>

using namespace std;


void Tests()
{

    int i = 10;
    int *ptr = &i;
    printf("size of ptr %d\n", sizeof(*ptr));
    double j = 20;
    ptr = reinterpret_cast<int *>(&j);
    printf("size of ptr %d\n", sizeof(*ptr));


    double k = 10.0;
    double *dptr = &k;

    int h = 1000;
    dptr = reinterpret_cast<double *>(&h);
    printf("size of dptr : %d\n", sizeof(dptr));

    int p1 = 10;
    int *ptr1 = &p1;
    int p2 = 10;
    int *ptr2 = &p2;

    int p = 0x120230f - 0x120230c;
    printf("P is %d\n", p);


    int x = 10;
    int &y = x;

    int z = y;
    z = 20;
    x = 30;
    printf("%d\n", y);

}

const int max_card = 100;
enum class Bool
{
    False,
    True
};

class Set
{
public:
    void EmptySet() { card = 0; }

    Bool Member(const int);

    void AddElem(const int);

    void RmvElem(const int);

    void Copy(Set &);

    Bool Equal(Set &);

    void Intersect(Set &, Set &);

    void Union(Set &, Set &);

    void Print();

private:

    int elem[max_card];
    int card;
};

//Bool Set::Member(const int elem)
//{
//    for(auto i = 0; )
//}

//class Point
//{
//
//    int x;
//    int y;
//
//public:
//
//    Point() {}
//
//    Point(int _x, int _y) : x{_x}, y{_y}
//    {
//
//    }
//
//    void Print()
//    {
//        printf("X %d Y %d\n", x, y);
//    }
//
//    ~Point()
//    {
//        printf("Point %d,%d deleted\n", x, y);
//    }
//
////    Point operator+(const Point &p) const;
//
//    friend Point operator+(const Point &p1, const Point &p2);
//};

//Point operator+(const Point &p1, const Point &p2)
//{
//    return {p1.x + p2.x, p1.y + p2.y};
//}

//Point Point::operator+(const Point &p) const
//{
//    return {x + p.x, y + p.y};
//}

//class Image
//{
//    const int w = 1000;
//    int h;
//    static int x;
//    static const int len;
//
//    int &width = h;
//
//public:
//
//    Image(const int _w, const int _h) : w{_w}, h{_h}
//    {
//    }
//
//};

class Table;
//
//typedef int (Table::*Compare)(const char *, const char *);

/*
 * template<class Criterion>
void filter(DataSet* data, Criterion criterion); // Compliant, uses the more efficient template argument

using Callback = std::function<void(EventInfo const&)>;
class Button {
public:
    void addOnClick(Callback c) {myOnClickHandler = c;} // Compliant, uses the more flexible std::function
private:
    Callback myOnClickHandler;
};

 */
//
//
//using Compare = std::function<int(const char *, const char *)>;
//
//typedef int (Table::*Compre)(const char *, const char *);
//
//using Comp = int (Table::*)(const char *, const char *);
//
//class Table
//{
//public:
//
//    Table(const int clots);
//
//    int Search(const char *item, Compre &);
//
//    int NormalizedComp(const char *, const char *);
//};
//
//Table::Table(const int clots) {}
//
//auto Table::Search(const char *item, Compre &comp) -> int
//{
//    return (this->*comp)(item, item);
//}
//
//int Image::x = 10;
//
//
//class Rectangle
//{
//    Point topLeft;
//    Point bottomLeft;
//
//public:
//    Rectangle(int x1, int y1, int x2, int y2) : topLeft(x1, y1), bottomLeft(x2, y2) {}
//
//};
//
//class Polygon
//{
//    Point *vertices;
//    int n_vertices;
//};
//
//void func()
//{
//    printf("Global func...\n");
//}
//
//class Process
//{
//public:
//
//    void func();
//
//    class ChildProcess
//    {
//    public:
//        void func()
//        {
//            Process p;
//            p.func();
//        }
//    };
//};
//
//void Process::func()
//{
//    printf("Local func...\n");
//}
//
//void test()
//{
////    ::func();
////    Process p;
////    p.func();
//
//    Process::ChildProcess cp;
//    cp.func();
//}
//
//class Employee
//{
//public:
////    Employee(int a){}
//    char *name;
//    int age;
//    double salary;
//};
//
//union Value
//{
//    double a;
//    long b;
//    string s;
//    int i;
//};
//
////class B
////{
////    string name;
////public:
////    B(const string &&n) : name{n}
////    {
////        printf("Class B: %s initializing...\n", name.c_str());
////    }
////
////    ~B()
////    {
////        printf("Class B: %s destroying...\n", name.c_str());
////    }
////};
//
////class A
////{
////    B *b3;
////    B b1;
////    B b2;
////
////public:
////    A(string name) : b2{name + " B2"}, b1{name + " B1"}, b3(new B(name + " B3")) {}
////
////
////    ~A()
////    {
////        delete b3;
////    };
////
////};
//
//typedef unsigned int Bit;
//
//class Packet
//{
////public:
//    Bit type: 2;
//    Bit ack: 1;
//    Bit channel: 4;
//    Bit seqNo: 4;
//    Bit moreData: 1;
//};
//
//
//long GetTime(void)
//{
//
//}
//
//void GetTime(int i, int j, int k)
//{
//
//}
//
//class A
//{
//public:
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
//
//    B()
//    {
//        printf("B called\n");
//    }
//
//    ~B()
//    {
//        printf("B deleted\n");
//    }
//};
//
//class C : public B, public A
//{
//public:
//    C()
//    {
//        printf("C called\n");
//    }
//
//    ~C()
//    {
//        printf("C deleted\n");
//    }
//};

class Point
{
    int _x{0};
    int _y{0};
public:
    Point() = default;

    Point(int x) : _x{x}, _y{x} {}

    Point(int x, int y) : _x{x}, _y{y} {}

    friend Point operator-(Point &p1, Point &p2);

    friend Point operator+(Point &p1, Point &p2);

    int GetX() const { return _x; }

    int GetY() const { return _y; }
};

Point operator-(Point &p1, Point &p2)
{
    return {p1.GetX() - p2.GetX(), p1.GetY() - p2.GetY()};
}

Point operator+(Point &p1, Point &p2)
{
    return {p1.GetX() + p2.GetX(), p1.GetY() + p2.GetY()};
}

class Rectangle
{
    Point bottom;
    Point top;
public:
    Rectangle(int x1, int y1, int x2, int y2) : bottom{x1, y1}, top{x2, y2} {}

    Rectangle(Point &p, Point &s) {}

    explicit operator Point() { return bottom - top; }

    friend Rectangle operator+(Rectangle &r, Rectangle &p);
};

//Rectangle operator+(Rectangle &r, Rectangle &p)
//{
//    return Rectangle(Point(r.top.GetX() + p.bottom.GetX()), Point(r.top.GetY() + p.bottom.GetY()));
//}

class A
{
    int _x;
    int _y;
public:
    A(int x, int y) : _x{x}, _y{y} {}

    friend ostream &operator<<(ostream &os, A &a);

    friend istream &operator>>(istream &is, A &a);

    int GetX() const { return _x; }

    int GetY() const { return _y; }

    void SetX(int x) { _x = x; }

    void SetY(int y) { _y = y; }
};

ostream &operator<<(ostream &os, A &a)
{
    os << a.GetX() << ' ' << a.GetY();
    return os;
}

istream &operator>>(istream &is, A &a)
{
    int x;
    is >> x;
    a.SetX(x);
    int y;
    is >> y;
    a.SetY(y);
    return is;

}

const int max_points = 512;

class P
{
public:
    void *operator new(size_t bytes);

    void operator delete(void *ptr, size_t bytes) noexcept;

private:
    int xval;
    int yval;

    static union Block
    {
        int xy[2];
        Block *next;
    } *blocks;

    static Block *freeList;
    static int used;
};

P::Block *P::blocks = new Block[max_points];
P::Block *P::freeList = nullptr;
int P::used = 0;

void *P::operator new(size_t bytes)
{
    Block *res = freeList;
    return used < max_points ? &(blocks[used++]) : (res == nullptr) ? nullptr : (freeList->next, res);
}

void P::operator delete(void *ptr, size_t bytes) noexcept
{
    ((Block *) ptr)->next = freeList;
    freeList = (Block *) ptr;
}

int main()
{

    P *p = new P;
    delete p;
    P *pArr = new P[10];
    delete[] pArr;
    return 0;
}

