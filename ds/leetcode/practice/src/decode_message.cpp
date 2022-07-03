//
// Created by sajith on 7/3/22.
//
#include "base.h"

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> mp;
        int i = 0;
        for (const auto &item: key)
        {
            if (item != ' ' && mp.count(item) == 0 && i < 26)
            {
                mp[item] = char(97 + i);
                ++i;
            }

            if (i == 26) break;
        }

        for (auto &item: message)
        {
            if (item != ' ')
            {
                item = mp[item];
            }
        }

        return message;
    }
};

int main()
{
    Solution solution;
    string key{"eljuxhpwnyrdgtqkviszcfmabo"};
    string mes{"zwx hnfx lqantp mnoeius ycgk vcnjrdbv"};
    cout<< solution.decodeMessage(key, mes);
    return 0;
}