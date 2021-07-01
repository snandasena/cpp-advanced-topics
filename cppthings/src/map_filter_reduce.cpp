//
// Created by sajith on 7/1/21.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{

    vector<int> inCollection{11, 12, 13, 14, 15, 16, 17, 18, 19};
    vector<int> outCollection;
    vector<int> filterCollection;

    // MAP
    std::transform(inCollection.begin(), inCollection.end(), std::back_inserter(outCollection), [](const int &value)
    {
        return value * 3;
    });

    // FILTER
    std::copy_if(outCollection.begin(), outCollection.end(), std::back_inserter(filterCollection), [](const int &value)
    {
        return value % 2 != 0;
    });


    // REDUCE
    int res = std::accumulate(filterCollection.begin(), filterCollection.end(), 0, [](int total, int current)
    {
        return total + current;
    });

    cout << res << endl;

    return 0;
}