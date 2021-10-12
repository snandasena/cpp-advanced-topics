//
// Created by sajith on 10/12/21.
//

#include "base.h"

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1;
        int r = n;
        int guz;
        int mid;
        while (l <= r)
        {
            mid = l + ((r - l) >> 1);
            guz = guess(mid);
            if (guz == 0)
            {
                return mid;
            } else if (guz == -1)
            {
                r = mid - 1;
            } else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};


int main()
{
    Solution solution;
    cout << solution.guessNumber(2) << endl;
    return 0;
}