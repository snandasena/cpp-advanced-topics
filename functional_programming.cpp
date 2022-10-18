//
// Created by sajith on 10/7/22.
//

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};

    auto res = std::reduce(v.begin(), v.end(), 0, [](int a, int b)
    { return a + b; });

    cout << res << endl;

    return 0;
}