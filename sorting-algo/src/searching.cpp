//
// Created by sajith on 12/24/21.
//

#include "bin_search.h"

using std::cout;
using std::endl;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50};
    int res = BinarySearchIterative(v, 3);
    cout << res << endl;

    res = BinarySearchRecursive(v, 0, v.size() - 1, 50);
    cout<< res<<endl;

    return 0;
}