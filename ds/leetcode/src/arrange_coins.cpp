//
// Created by sajith on 11/5/21.
//

#include "base.h"

using ll = long int;

class Solution
{
public:
    int arrangeCoins2(int n)
    {
        if (n == 1) return 1;
        ll pre = 1;
        int i = 1;
        while (pre < n)
        {
            ++i;
            pre += i;
        }

        if (pre > n) return i - 1;
        else return i;
    }

    int arrangeCoins(int n)
    {
        int l = 0, r = n;
        ll sum, mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            sum = mid * (mid + 1) / 2;
            if (sum == n) return static_cast<int>(mid);
            else if (n < sum) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }

};


int main()
{
    Solution solution;
    cout << solution.arrangeCoins(1) << endl;
    return 0;
}