//
// Created by sajith on 1/24/22.
//

#include "base.h"

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        auto len = static_cast<int>(word.length());
        if (len == 1) return true;

        bool allcaps = true;
        bool alllow = true;

        for (int i = 1; i < len; ++i)
        {
            if (islower(word[i]))
            {
                allcaps = false;
            }

            if (isupper(word[i]))
            {
                alllow = false;
            }
        }

        bool fU = isupper(word[0]);
        bool fL = islower(word[0]);

        if (fU)
        {
            if (allcaps) return true;
            if (alllow) return true;
        }
        else if (fL && alllow) return true;

        return false;
    }
};

int main()
{

    Solution sol;

    string str{"l"};
    cout << boolalpha << sol.detectCapitalUse(str);
    return 0;
}