//
// Created by sajith on 7/6/22.
//
class Solution
{
public:
    int fib(int n)
    {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        int a = 0;
        int b = 1;
        // 0, 1, 1, 2, 3, 5,
        int ans;
        for (int i = 2; i <= n; ++i)
        {
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    }
};