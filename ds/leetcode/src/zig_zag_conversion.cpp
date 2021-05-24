//
// Created by sajith on 5/24/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        vector<string> rows(min(numRows, (int) s.size()));
        int curRow = 0;
        bool goinDown = false;

        for (char c: s)
        {
            rows[curRow] += c;
            if (curRow == 0 || curRow == numRows - 1)
            {
                goinDown = !goinDown;
            }

            curRow += goinDown ? 1 : -1;
        }

        string res;
        for (string &row: rows)
        {
            res += row;
        }

        return res;
    }
};


int main()
{
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3);

    return 0;
}