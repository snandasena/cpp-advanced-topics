//
// Created by sajith on 11/15/21.
//

#include <iostream>
#include <string>

using namespace std;


void printString(string str)
{
    cout << str << endl;
}

int main()
{
    string s = "Hello from main";
    string s2 = move(s);
    printString(s2);
    cout<<s<<endl;
    return 0;
}