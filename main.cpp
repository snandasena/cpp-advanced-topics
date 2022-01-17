

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
    string s{"waterbottle"};
    string k{"erbottlewat"};

    s +=s;
    auto i = s.find(k);
    cout<<i<<endl;
    cout<< s.substr(i, k.length())<<endl;

    string x{"5"};
    cout<<stoi(x)<<endl;
    return 0;
}

// 14 + 13 = 27