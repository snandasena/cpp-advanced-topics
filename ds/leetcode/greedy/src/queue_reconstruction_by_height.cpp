//
// Created by sajith on 6/29/22.
//


#include "base.h"

template<typename T>
struct Compare
{
    bool operator()(const vector<T> &a, const vector<T> b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
};

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), Compare<int>());
        vector<vector<int>> ans(people.size());

        for (auto i = 0; i < people.size(); ++i)
        {
            auto idx = people[i][1];
            ans.insert(ans.begin() + idx, people[i]);
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> v{{7, 0},
                          {4, 4},
                          {7, 1},
                          {5, 0},
                          {6, 1},
                          {5, 2}};
    solution.reconstructQueue(v);
    return 0;
}