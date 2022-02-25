//
// Created by sajith on 2/25/22.
//

#include "base.h"

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        size_t i = 0;
        size_t j = 0;
        size_t N = version1.size();
        size_t M = version2.size();
        int x = 0;
        int y = 0;
        while (i < N || j < M)
        {
            while (i < version1.size() && version1[i] != '.')
            {
                x = x * 10 + (version1[i] - '0');
                ++i;
            }

            while (j < version2.size() && version2[j] != '.')
            {
                y = y * 10 + (version2[j] - '0');
                ++j;
            }
            if (x < y) return -1;
            else if (x > y) return 1;

            ++i;
            ++j;
            x = 0;
            y = 0;
        }
        return 0;
    }
};


int main()
{
    Solution solution;
    cout << solution.compareVersion("1.0.1", "1") << endl;
//

    return 0;
}

