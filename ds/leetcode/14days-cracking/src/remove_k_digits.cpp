//
// Created by sajit on 2/18/2022.
//

#include "base.h"

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == 0) return num;
        else if (num.empty()) return "0";

        stack<int> stck;

        for (auto const &c: num)
        {
            while (k > 0 && !stck.empty() && c < stck.top())
            {
                --k;
                stck.pop();
            }

            if (!stck.empty() || c != '0')
            {
                stck.push(c);
            }
        }

        while (k-- && !stck.empty())
        {
            stck.pop();
        }

        if (stck.empty()) return "0";
        auto N = static_cast<int > (num.size());
        while (!stck.empty())
        {
            num[N - 1] = stck.top();
            stck.pop();
            --N;
        }

        return num.substr(N);
    }
};

/*
 * "10200"
1

 */
int main()
{

    Solution sol;
    cout << sol.removeKdigits("10200", 1) << endl;
    return 0;
}