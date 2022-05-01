

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

class Point
{

    int x;
    int y;

public:

    Point(int _x, int _y) : x{_x}, y{_y}
    {

    }

    void Print()
    {
        printf("X %d Y %d\n", x, y);
    }
};

class Image
{
    const int w = 1000;
    int h;
    static int x;
    static const int len;

    int &width = h;

public:

    Image(const int _w, const int _h) : w{_w}, h{_h}
    {
    }

};

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


using Compare = std::function<int(const char *, const char *)>;

typedef int (Table::*Compre)(const char *, const char *);

using Comp = int (Table::*)(const char *, const char *);

class Table
{
public:

    Table(const int clots);

    int Search(const char *item, Compre &);

    int NormalizedComp(const char *, const char *);
};

Table::Table(const int clots) {}

auto Table::Search(const char *item, Compre &comp) -> int
{
    return (this->*comp)(item, item);
}

int Image::x = 10;


int main()
{
    Point pt(10, 20);
    pt.Print();
    pt.Point::Print();

    Image i(10, 20);

    Table table(10);
//    table.Search("Hello", std::strcmp);


    return 0;
}

