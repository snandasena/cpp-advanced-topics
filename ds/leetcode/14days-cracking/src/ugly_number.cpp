//
// Created by sajith on 11/23/21.
//

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n < 1) return false;

        while (n % 2 == 0)
        {
            n /= 2;
        }

        while (n % 3 == 0)
        {
            n /= 3;
        }

        while (n % 5 == 0)
        {
            n /= 5;
        }

        if (n == 1) return true;
        return false;
    }
};


int main()
{
    Solution solution;
    solution.isUgly(6);
    return 0;
}