//
// Created by sajith on 9/22/21.
//

#include "base.h"

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        for (int &x: nums)
        {
            mp[x] = mp[x] + 1;

            if (mp[x] > 1)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{

    Solution solution;
    vector<int> v = {1, 2, 3, 1};
    cout << boolalpha << solution.containsDuplicate(v);
    return 0;
}