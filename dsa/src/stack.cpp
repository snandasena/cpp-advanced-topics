//
// Created by sajith on 12/29/21.
//

#include "stack.h"

#include <bits/stdc++.h>

int main()
{
    using namespace std;

    Stack stck;
    stck.Push(10);
    stck.Push(20);
    stck.Push(30);
    stck.Push(40);

    cout << stck.Top() << endl;
    stck.Pop();
    cout << stck.Top() << endl;

    return 0;
}
