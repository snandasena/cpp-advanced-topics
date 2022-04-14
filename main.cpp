

#include <bits/stdc++.h>
//#include <iostream>
//#include <type_traits>
//
using namespace std;

//
//struct A
//{
//    void disp()
//    {
//        cout << "Base A\n";
//    }
//};
//
//
//struct B : A
//{
//    void disp()
//    {
//        cout << "Base B\n";
//    }
//};
//
//struct C : B
//{
//    void disp()
//    {
//        cout << "C child\n";
//    }
//};
//
//
//struct D : A
//{
//    void disp()
//    {
//        cout << "Base D";
//    }
//};
//
//struct F : virtual B, virtual D
//{
//    void disp()
//    {
//        B::disp();
//    }
//};
//
//int BinaryGap(int N)
//{
//    int y = N;
//    int i = 0;
//    while (y != 0)
//    {
//        ++i;
//        y /= 2;
//    }
//
//    int start = 0;
//    int end = 0;
//    bool flag{false};
//    int x = 1;
//    int k = 1;
//    for (int j = 0; j <= i; ++j)
//    {
//        y = (N & x);
//        if (!flag && y != 0)
//        {
//            flag = true;
//            start = j;
//            k = x;
//        }
//
//        if (y != 0)
//        {
//            end = j;
//        }
//
//        x *= 2;
//    }
//
//    if (start == end) return 0;
//    x = k;
//    int curr = 0;
//    int ans = 0;
//    for (int j = start; j <= end; ++j)
//    {
//        y = (N & x);
//        if (y == 0)
//        {
//            ++curr;
//        }
//        else
//        {
//            ans = max(curr, ans);
//            curr = 0;
//        }
//
//        x *= 2;
//    }
//    return ans;
//}
//
//
//int missing_number(vector<int> &v)
//{
//    int N = v.size();
//    sort(v.begin(), v.end());
//    for (int i = 1; i <= N; ++i)
//    {
//        if (i != v[i - 1]) return i;
//    }
//
//    return N + 1;
//}
//
//
//void ptest(int *pVal)
//{
//    *pVal = 10;
//}
//
//void reftest(int &pVal)
//{
//    pVal = 50;
//}
//
//
//struct PStruct
//{
//    int x;
//    int y;
//};
//
//void pStructTest(PStruct &pStruct)
//{
//    pStruct.x = 10;
//    pStruct.y = 50;
//}
//
//PStruct *Get()
//{
//    PStruct ref{};
//    ref.x = 9999;
//    ref.y = 66666;
//    auto p = make_shared<PStruct>(ref);
//    return p.get();
//}
//
//class Account
//{
//    double balance;
//public:
//
//    Account(double initBal) : balance{initBal} {}
//
//    double GetBalance() const { return balance; }
//};
//
//double Account = 23.999;
//
//
//struct X
//{
//    char a; // 1+3
//    char _pad1[3];
//    int b; // 4
//    short c; // 2
//    char d; // 1+1
//    char _pad2[1];
//} bar[3];
//
//class CX
//{
//    char a;
//    int b;
//    short c;
//    char d;
//
//    int temp() { return 0; }
//};
//
//union UX
//{
//    int b;
//    short c;
//    double e;
//    char d;
//};
//
//
//class Animal
//{
//    string name;
//    string type;
//
//public:
//    Animal(string n, string t) : name{move(n)}, type{move(t)} {}
//
//    Animal(Animal &animal) = default;
//
//    Animal &operator=(Animal const &other) = default;
//
//    virtual void Noise()
//    {
//        cout << "Animal Noise\n";
//    };
//
//    virtual ~Animal()
//    {
//        cout << "Deleted Animal\n";
//    }
//
//    string GetName() const { return name; }
//
//    string GetType() const { return type; }
//};
//
//class Cat : public Animal
//{
//    string bread;
//
//public:
//    Cat(string b, string n, string t) : Animal(move(n), move(t)), bread{move(b)} {}
//
//    ~Cat()
//    {
//        cout << "Deleted Cat\n";
//    }
//
//    void Noise() override
//    {
//        cout << "Cat Noise\n";
//    }
//
//    string GetBread() const { return bread; }
//};
//
//
//class AnimalBest
//{
//    string name;
//    string type;
//
//public:
//
//    AnimalBest(string n, string t) : name{move(n)}, type{move(t)} {}
//
//    virtual void Noise()
//    {
//        cout << "Animal Noise\n";
//    }
//
//    virtual ~AnimalBest() = default;
//
//    string GetName() const { return name; }
//
//    string GetType() const { return type; }
//};
//
//class CatBest : public AnimalBest
//{
//    string bread;
//public:
//    CatBest(string b, string n, string t) : AnimalBest(move(n), move(t)), bread{move(b)} {}
//
//    void Noise() override
//    {
//        cout << "Cat Noise\n";
//    }
//
//    string GetBread() const { return bread; }
//};
//
//void AnimalBestTestAPI()
//{
//    unique_ptr<CatBest> cat = make_unique<CatBest>("B", "N", "T");
//    cout << cat->GetName() << endl;
//    cout << cat->GetType() << endl;
//}
//
//class AC
//{
//    int a; // 4
//    char c; // 1
//    char ac; // 1
//    int d; // 4
//
//};
//
//class IndiaBix
//{
//    int val;
//public:
//    void SetValue(char *str1, char *str2)
//    {
//        val = strcspn(str1, str2);
//    }
//
//    void ShowValue()
//    {
//        cout << val;
//    }
//};
//
//union XU
//{
//    int a;
//    char b;
//};
//
//




double fun(double d);
//int fun(double d);

double fun(double d);


double fun(double d)
{

}


struct Point
{
    int x;
    int y;
};

constexpr int x = 10;
constexpr int y = 2;

constexpr Point scale(Point p) { return {x * p.x, y * p.y}; }

void user(Point p1)
{
    Point p2{10, 20};
    Point p3 = scale(p1);
    Point p4 = scale(p2);

//    constexpr Point p5 = scale(p1);
//    constexpr Point p6 = scale(p2);
}

enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    agu,
    oct,
    nov,
    dec
};

vector<int> month_tbl(12);

ostream &operator<<(ostream &out, const Month &mr)
{
    out << "Month number is: " << month_tbl[int(mr)];
    return out;
}

class Year
{
    static const int min = 1800;
    static const int max = 2200;

public:

    class Invalid : public std::exception
    {
    };

    Year(int x) : y{x}
    {
        if (x < min || x > max) throw Invalid{};
    }

private:
    int y;
};

class Date
{
public:
    Date(Year y, Month m, int d);

private:
    Year _y;
    Month _m;
    int _d;
};


int menu(char *optional1 ...)
{
    va_list args;
    char *option = optional1;
    int count = 0;
    int choice = 0;

    va_start(args, optional1);
    do
    {
        cout << ++count << " " << option << '\n';
    } while ((option = va_arg(args, char *)) != nullptr);

    va_end(args);
}


#define MIN(x, y) ( (x<y)?(x):(y))
#define MAX(x,y)((x>y)?(x):(y))
#define SUM(x,y)(MIN(x,y) + MAX(x,y))
//#define REC(x, y)(0+REC(x, y))

int main()
{
    std::iota(month_tbl.begin(), month_tbl.end(), 0);
    max(1, 1);
    cout << Month::agu << endl;

    menu("option1", "option2", "option3", nullptr);

    int a = SUM(1, 10);
    int arr[] = {1,10,10,10,10,10};
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(*arr) <<endl;

    return 0;
}

