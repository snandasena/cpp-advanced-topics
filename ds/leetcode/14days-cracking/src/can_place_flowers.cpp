//
// Created by sajith on 1/18/22.
//


#include "base.h"

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &f, int n)
    {
        if(n==0) return true;

        f.insert(f.begin(), 0);
        f.push_back(0);
        auto N = static_cast<int>(f.size());
        int i = 0;
        int ans = 0;
        while (i < N)
        {
            if (i - 1 >= 0 && f[i - 1] == 0 && f[i] == 0 && i + 1 < N && f[i + 1] == 0)
            {
                ++ans;
                if (ans >= n) return true;
                ++i;
            }
            ++i;
        }

        return false;
    }
};


int main()
{

    Solution sol;
    vector<int> v{1,0};
    cout << boolalpha << sol.canPlaceFlowers(v, 1) << endl;
    return 0;
}