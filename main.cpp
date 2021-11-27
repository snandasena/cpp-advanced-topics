

#include <bits/stdc++.h>

using namespace std;

struct A
{
    void disp()
    {
        cout << "Base A\n";
    }
};


struct B : A
{
    void disp()
    {
        cout << "Base B\n";
    }
};

struct C : B
{
    void disp()
    {
        cout << "C child\n";
    }
};


struct D : A
{
    void disp()
    {
        cout << "Base D";
    }
};

struct F : virtual B, virtual D
{
    void disp()
    {
        B::disp();
    }
};

int main()
{

    C c;
    c.disp();
    F f;
    f.disp();

    int t = 1;
    for (int i = 0; i < 10; ++i)
    {
        t *= 3;
        cout << t << "\t";
    }


    return 0;
}

// 14 + 13 = 27