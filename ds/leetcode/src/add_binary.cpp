//
// Created by sajith on 9/9/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;

        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += a[i--] - '0';
            }

            if (j >= 0)
            {
                sum += b[j--] - '0';
            }
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }

        if (carry == 1)
        {
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution solution;
    cout << solution.addBinary("11", "1") << endl;
    return 0;
}