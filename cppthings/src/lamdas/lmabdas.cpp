//
// Created by sajith on 11/14/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> v{1, 2, 3, 4, 1,3, 2, 5};
    auto isOdd = [](int const &num) { return num % 2 == 1; };
    auto ans = std::count_if(v.begin(), v.end(), isOdd);
    cout << ans<<endl;
    return 0;
}