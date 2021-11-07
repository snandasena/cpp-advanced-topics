//
// Created by sajith on 11/7/21.
//

#include "base.h"


class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num2 == "0" || num1 == "0") return "0";

        vector<int> res(num2.size() + num1.size(), 0);
        for (int i = num1.size() - 1; i >= 0; --i)
        {
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += res[i + j + 1] / 10;
                res[i + j + 1] %= 10;
            }
        }

        string ans;
        int i = 0;
        while (res[i] == 0) ++i;
        while (i < res.size()) ans += to_string(res[i++]);
        return ans;
    }


    string multiply2(string num1, string num2)
    {
        string ans(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j)
            {
                int sum = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                ans[i + j + 1] = (sum % 10) + '0';
                carry = sum / 10;
            }
            ans[i] += carry;
        }
        size_t f = ans.find_first_not_of('0');
        if (f != string::npos)
        {
            return ans.substr(f);
        }
        return "0";
    }
};


int main()
{
    Solution solution;
    cout << solution.multiply("10", "20") << endl;
    return 0;
}