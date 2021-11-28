//
// Created by sajith on 11/21/21.
//

#include <iostream>
#include <algorithm>
#include <numeric>

#include "resource.h"

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

    auto newend = remove(source.begin(), source.end(), 3);
    auto s = source.size();
    auto logicalsize = newend - source.begin();
    source.erase(newend, source.end());

    vector<Resource> vr(2);
    vr[0].setValue(8);
    vr[1].setValue(9);

    auto newend2 = remove_if(vr.begin(), vr.end(), [](Resource const &r) { return r.getValue() == 8; });
    vr.erase(newend2, vr.end());


    // FILL
    vector<int> v6(10);
    fill(v6.begin(), v6.end(), 1);
    fill_n(v6.begin(), 6, 2);
    iota(v6.begin(), v6.end(), 10);

    int idx = 10;
    generate(v6.begin(), v6.end(), [&idx]() { return --idx; });
    source = v6;
    idx = 1;
    generate_n(v6.begin(), 7, [&idx]() { return idx *= 2; });

    replace(v6.begin(), v6.end(), 2, 7);
    replace_if(v6.begin(), v6.end(), [](int const &i) { return i < 16; }, 7);

    transform(source.begin(), source.end(), source.begin(), [](int const &i) { return i * 2; });
    transform(source.begin(), source.end() - 1, source.begin() + 1, v6.begin(),
              [](int const &ele1, int const &ele2) { return ele1 - ele2; });

    vector<int> v7(10);
    transform(source.begin(), source.end(), v6.begin(), v7.begin(),
              [](int const elm1, int const elm2) { return elm1 + elm2; });
    unique(v2.begin(), v2.end());
    v2[3] = -2;
    auto v8 = v2;
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    unique_copy(v8.begin(), v8.end(), v7.begin());

    string sentence = "Hello, World!";
    reverse(sentence.begin(), sentence.end());

    iter_swap(v7.begin(), v7.end()-1);
    string orig="               ";
    reverse_copy(sentence.begin(), sentence.end(), orig.begin());
    string  x{"abcdef"};
    iota(x.begin(), x.end(), 'g');
    return 0;
}