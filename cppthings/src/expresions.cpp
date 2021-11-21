//
// Created by sajith on 11/20/21.
//
#include <bits/stdc++.h>
#include <stdint.h>

using namespace std;

int fun(int i)
{
    return ++i;
}

union S
{
    int32_t a;
    int16_t b;
    int8_t c;
};

typedef struct
{
    int sun: 1;
    int mon: 1;
    int tue: 1;
    int wen: 1;
} weekdays;

struct Test
{
    int a;
    string *pStr;
};

struct X
{
    void f() { cout << "Call from f()\n"; }

    void g() {}
};

int main()
{
    int i = fun(10);
    cout << i << endl;

    cout << sizeof(S) << endl;
    cout << sizeof(weekdays) << endl;

    int8_t a = 200;
    cout << INT8_MAX << endl;
    cout << INT8_MIN << endl;
    cout << INT16_MAX << endl;
    cout << INT16_MIN << endl;
    uint8_t b = 100;
    if (a > b) cout << "greater\n";
    else cout << "less\n";

    int x = 10;
    int y = -3;
    x = +y;

    cout << x << endl;

    Test t;
    t.pStr;

//    Test *pT = new Test;
//    pT.*pStr = "";
//    t.*a = 10;

    typedef void (X::*pointer)();
    pointer somepter = &X::f;

    X xm;
    (xm.*somepter)();

    for (int j = 1; j < 10; j++)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    int j =1;
    while (j< 10)
    cout<< ++j<<" ";
    cout<<endl;

    j =1;
    loop:
        cout<<j++<<" ";
        if(j< 10) goto loop;


    return 0;
}

// 010
// 101

// 011
// 101

// 100
// 010