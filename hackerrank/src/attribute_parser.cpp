//
// Created by sajith on 11/4/22.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct Tag
{
    string name;
    vector<pair<string, string>> attrs;
    vector<Tag> children;
};

void parser(Tag *root, string str)
{

}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    int Q;

//    cin>>N>>Q;
//    while()

    string str;
    getline(cin, str);

    cout << str << endl;
    return 0;
}
