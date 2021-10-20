//
// Created by sajith on 10/19/21.
//


#include <iostream>

using namespace std;


class Test
{

public:

public:
    static int cont;
    int a;
    int b;

    Test()
    {
        a = 10;
        b = 10;
        cont++;
    }

    static int getCount()
    {
        return cont;
    }
};

int Test::cont = 0; // very important to do

int main()
{
    Test t1;
    Test t2;
    cout << t1.cont << endl;
    cout << t2.cont << endl;
    cout << Test::cont << endl;
    cout << Test::getCount() << endl;
    return 0;
}