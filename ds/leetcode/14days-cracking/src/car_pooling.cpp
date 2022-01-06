//
// Created by sajith on 1/6/22.
//

#include "base.h"

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {

        vector<int> v(1001, 0);
        for (auto &trip : trips)
        {
            v[trip[1]] += trip[0];
            v[trip[2]] -= trip[0];
        }
        int empty = 0;
        for (auto &i: v)
        {
            empty += i;
            if (empty > capacity) return false;
        }

        return true;
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> v{{4, 5, 6},
                          {6, 4, 7},
                          {4, 3, 5},
                          {2, 3, 5}};
    cout << boolalpha << sol.carPooling(v, 13) << endl;
    return 0;
}