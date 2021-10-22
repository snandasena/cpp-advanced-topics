//
// Created by sajith on 10/22/21.
//

#include "base.h"

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;
        for (char &c: s)
        {
            mp[c]++;
        }

        vector<pair<char, int>> vec;
        for (auto &p: mp)
        {
            vec.push_back({p.first, p.second});
        }

        sort(vec.begin(), vec.end(), [](auto &p1, auto &p2)
        {
            return p1.second > p2.second;
        });

        string ans;
        for (auto it = vec.begin(); it != vec.end(); ++it)
        {
            for (int i = 0; i < it->second; ++i)
            {
                ans += it->first;
            }
        }
        return ans;
    }
};


int main()
{
    return 0;
}