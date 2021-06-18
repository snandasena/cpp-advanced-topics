//
// Created by sajith on 6/18/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        else if (n == 2)
        {
            return "11";
        }
        else
        {
            string str = countAndSay(n - 1);
            int i = 0;
            string res = "";
            while (i < str.length())
            {
                int cnt = 0;
                char digit = str.at(i);

                while (i < str.length() && str.at(i) == digit)
                {
                    cnt++;
                    i++;
                }

                res.push_back(cnt + '0');
                res.push_back(digit);
            }

            return res;
        }
    }
};

int main()
{
    Solution solution;
//    cout << solution.countAndSay(1)<<endl;
//    cout << solution.countAndSay(2)<<endl;
//    cout << solution.countAndSay(3)<<endl;
//    cout << solution.countAndSay(4)<<endl;
//    cout << solution.countAndSay(5)<<endl;
    cout << solution.countAndSay(6) << endl;
    return 0;
}