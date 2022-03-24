//
// Created by sajith on 3/24/22.
//

#include "base.h"

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        if (people.size() == 1) return 1;

        sort(people.begin(), people.end());
        int ans = 0;
        int i = 0;
        int j = people.size() - 1;
        while (i <= j)
        {
            ++ans;
            if (people[i] + people[j] <= limit)
            {
                ++i;
            }
            --j;
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> v{3, 5, 3, 4};
    cout << solution.numRescueBoats(v, 5);
    return 0;
}