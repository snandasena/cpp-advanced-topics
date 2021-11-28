//
// Created by sajith on 11/27/21.
//
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <deque>
#include <array>

using namespace std;

int main()
{
    vector<int> v1(10);
    fill(v1.begin(), v1.end(), 1);
    fill_n(v1.begin(), 6, 2);
    iota(v1.begin(), v1.end(), 1);

    vector<int> v2;
    fill_n(back_inserter(v2), 6, 2);
    generate_n(back_inserter(v2), 10, [n = 0]()mutable { return ++n; });

    deque<int> q3;
    fill_n(front_inserter(q3), 6, 2);
    generate_n(front_inserter(q3), 10, [n = 0]() mutable { return ++n; });
    return 0;
}