//
// Created by sajith on 3/20/22.
//

#include "base.h"

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        vector<int> t(7, 0);
        vector<int> b(7, 0);

        int mx1 = 0;
        int max_ele1 = 0;
        int mx2 = 0;
        int max_ele2 = 0;
        for (const auto &item : tops)
        {
            ++t[item];

            if (t[item] > max_ele1)
            {
                mx1 = item;
                max_ele1 = t[item];
            }
        }

        for (const auto &item : bottoms)
        {
            ++b[item];
            if (b[item] > max_ele2)
            {
                mx2 = item;
                max_ele2 = b[item];
            }
        }

        int ans = 0;
        if (max_ele1 >= max_ele2)
        {
            for (int i = 0; i < tops.size(); ++i)
            {
                if (tops[i] != mx1 && bottoms[i] != mx1) return -1;
                else if (tops[i] != mx1 && bottoms[i] == mx1) ++ans;
            }
        }
        else
        {
            for (int i = 0; i < tops.size(); ++i)
            {
                if (tops[i] != mx2 && bottoms[i] != mx2) return -1;
                else if (tops[i] == mx2 && bottoms[i] != mx2) ++ans;
            }
        }
        return ans;
    }
};

int main()
{

    Solution solution;
    vector<int> t{3, 5, 1, 2, 3};
    vector<int> b{5, 2, 6, 2, 3, 2};
    cout << solution.minDominoRotations(t, b) << endl;
}