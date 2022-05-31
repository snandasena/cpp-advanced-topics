//
// Created by sajith-csi on 5/31/2022.
//

#include "base.h"

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> st;
        int need  = 1<<k;
        string str;
        for (size_t i = k; i < s.size(); ++i)
        {
            str = s.substr(i-k, i);
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
    string s{"000011010111011001001111111001000100100100010100101100001101101101110001100100101111100111001001111001001010111010010101101001001110011100110101001001001000000110101001010011101100110110100010000"};
    Solution sol;
    cout<<boolalpha<< sol.hasAllCodes(s, 7);
    return 0;
}