//
// Created by sajith on 11/21/21.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> source{3, 6, 1, 0, -2, 5};
    vector<int> v2(source.size());

    copy(source.begin(), source.end(), v2.begin());
    auto v3 = source;

    auto pos = find(source.begin(), source.end(), 1);
    vector<int> v4(source.size());
    copy(source.begin(), pos, v4.begin());

    vector<int> v5(source.size());
    copy_if(source.begin(), source.end(), v5.begin(), [](int const &i) { return i % 2 == 0; });

    copy_n(v5.begin(), 3, v2.begin());

    copy(source.begin(), pos + 1, pos + 1);

    copy_backward(v3.begin(), v3.end(), source.end());
    copy_backward(source.begin(), source.end() - 1, source.end());

    auto newend = remove(source.begin(), source.end(),3 );
    auto s= source.size();
    auto logicalsize = newend - source.begin();
    source.erase(newend, source.end());
    return 0;
}