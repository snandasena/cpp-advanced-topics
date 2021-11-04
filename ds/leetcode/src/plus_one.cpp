//
// Created by sajith on 11/4/21.
//

#include "base.h"

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int num, sum, reminder = 1;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            sum = (digits[i] + reminder);
            num = sum % 10;
            reminder = sum > 9 ? 1 : 0;
            digits[i] = num;
        }
        if (reminder)
        {
//            vector<int> v(digits.size() + 1, 1);
//            for (int i = 1; i < v.size(); ++i)
//            {
//                v[i] = digits[i - 1];
//            }
//            return v;

            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


int main()
{
    Solution solution;
    vector<int> v = {9, 9, 9, 9};
    vector<int> ans = solution.plusOne(v);

    for (int &i:ans) cout << i << " ";

    return 0;
}