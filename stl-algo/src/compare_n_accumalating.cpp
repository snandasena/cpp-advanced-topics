//
// Created by sajith on 11/19/21.
//

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <numeric>
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

    total = accumulate(v1.begin(), v1.end(), 0, [](int const &t, int const &i)
    {
        return i % 2 == 1 ? t + i : t;
    });
    cout << total << endl;

    vector<string> v3{"one", "two", "three", "four", "five"};
    auto strTotal = accumulate(v3.begin(), v3.end(), string{}, [](string &tstr, string const &str)
    {
        return tstr += str + " ";
    });
    cout << strTotal << endl;

    auto firstThree = find(v1.begin(), v1.end(), 3);
    for_each(firstThree, v1.end(), [](int &i) { i = 0; });

    for_each(v1.begin(), v1.end(), [](int const &i) { cout << i << " "; });

    return 0;
}
