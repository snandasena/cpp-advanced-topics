//
// Created by sajith on 11/17/21.
//

#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v{1, 2, 3, 4, 5, 5, 6, 1, 2, 5, 5, 6, 1, 2};
    int const target = 5;\
    auto ans = count(v.begin(), v.end(), target);
    cout << ans << endl;


    list<int> l{1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4};
    ans = count(l.begin(), l.end(), target);
    cout << ans << endl;

    set<int> s{1, 2, 3, 4, 5, 6, 7, 8, 8, 10};
    ans = count(s.begin(), s.end(), 8);
    cout << ans << endl;

    auto ods = count_if(v.begin(), v.end(), [](int const &num) { return num % 2 == 0; });
    cout << ods << endl;

    auto allof_even = all_of(v.begin(), v.end(), [](int const &num) { return num % 2 == 0; });
    cout << boolalpha;
    cout << allof_even << endl;

    auto nonof_even = none_of(v.begin(), v.end(), [](int const &num) { return num % 2 == 0; });
    cout << nonof_even << endl;

    auto anyof_even = any_of(v.begin(), v.end(), [](int const &num) { return num % 2 == 0; });
    cout << anyof_even << endl;


    auto it = find(v.begin(), v.end(), 5);
    cout << *it << endl;

    if (it != v.end())
    {
        it = find(it, v.end(), 1);
        cout << *it << endl;
    }

    it = find_if(v.begin(), v.end(), [](int const &num) { return num == 6; });
    cout<< *it<<endl;

    return 0;
}