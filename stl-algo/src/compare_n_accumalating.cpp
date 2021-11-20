//
// Created by sajith on 11/19/21.
//

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{1, 2, 0, 4,};

    auto same = equal(v1.begin(), v1.end(), v2.begin(), v2.end());
    cout << boolalpha << same << endl;

    auto[first, second] = mismatch(v1.begin(), v1.end(), v2.begin());

    cout << *first << endl;
    cout << *second << endl;


    auto total = accumulate(v1.begin(), v1.end(), 0);
    cout << total << endl;

    return 0;
}
