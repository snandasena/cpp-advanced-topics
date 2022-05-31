//
// Created by sajith-csi on 5/31/2022.
//

#include "base.h"

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if(s.size() <k) return false;

        unordered_set<string> st;
        int need  = 1<<k;
        string str;
        for (size_t i = 0; i <= s.size()-k; ++i)
        {
            str = s.substr(i, k);
            if(!st.count(str))
            {
                st.insert(str);
                --need;
                if(need == 0) return true;
            }
        }
        return false;
    }
};

int main()
{
    string s{"0110"};
    Solution sol;
    cout<<boolalpha<< sol.hasAllCodes(s, 2);
    return 0;
}