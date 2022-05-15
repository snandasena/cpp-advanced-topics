//
// Created by sajith on 5/15/22.
//

#include <bits/stdc++.h>

using namespace std;
struct Pub
{
    int x;
    int y;
};

int main()
{
    Pub *p = reinterpret_cast<Pub *>(0x602000000010);
    printf("%d", p->x);
    return 0;
}
