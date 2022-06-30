//
// Created by sajith on 6/30/22.
//
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if(nums.empty()) return 0;
        set<int> st;
        for (const auto &item: nums)
        {
            st.insert(item);
        }

        int ans = 1;
        int curr;
        int curr_item;
        for (const auto &item: st)
        {
            if (st.count(item - 1) == 0)
            {
                curr = 1;
                curr_item = item;

                while (st.count(curr_item+1) > 0)
                {
                    ++curr;
                    ++curr_item;
                }

                ans = max(ans, curr);
            }
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    vector<int> v{1,2,300,200};
    cout << solution.longestConsecutive(v);
    return 0;
}
