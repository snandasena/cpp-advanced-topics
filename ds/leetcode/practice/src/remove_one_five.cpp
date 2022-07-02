//
// Created by sajith on 7/2/22.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    int removeOneFive(int N)
    {
        string str = to_string(N);
        int mx = -999999;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == '5')
            {
                auto n = str.substr(0, i) + str.substr(i + 1);
                mx = max(mx, stoi(n));
            }
        }
        return mx;
    }
};

int main()
{
    Solution solution;
    cout << solution.removeOneFive(-5859)<<endl;
    cout << solution.removeOneFive(15958)<<endl;
    cout << solution.removeOneFive(-5000)<<endl;
    cout << solution.removeOneFive(5005)<<endl;
    cout << solution.removeOneFive(5055)<<endl;
    return 0;
}