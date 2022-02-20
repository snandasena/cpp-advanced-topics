//
// Created by sajith on 2/19/22.
//

#include "base.h"

class Solution
{

public:
    string leftjustify(vector<string> &words, int diff, int i, int j)
    {
        int spacesOnRight = diff - (j - i - 1);
        string res{words[i]};
        for (int k = i + 1; k < j; ++k)
        {
            res += " " + words[k];
        }

        for (int l = 0; l < spacesOnRight; ++l)
        {
            res += " ";
        }
        return res;
    }

    string middleJustify(vector<string> &words, int diff, int i, int j)
    {
        int spacesNeeded = j - i - 1;
        int spaces = diff / spacesNeeded;
        int extraSpaces = diff % spacesNeeded;
        int spacesToApply;
        string res{words[i]};
        for (int k = i + 1; k < j; ++k)
        {
            spacesToApply = spaces + (extraSpaces-- > 0 ? 1 : 0);
            for (int l = 0; l < spacesToApply; ++l)
            {
                res += " ";
            }
            res += words[k];
        }
        return res;
    }

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> ans;
        int i = 0;
        auto N = static_cast<int>(words.size());
        int j;
        int lineLength;
        int diff;
        int numOfWords;
        while (i < N)
        {
            j = i + 1;
            lineLength = static_cast<int >(words[i].size());
            while (j < N && (lineLength + words[j].size() + (j - i - 1) < maxWidth))
            {
                lineLength += words[j].size();
                ++j;
            }
            diff = maxWidth - lineLength;
            numOfWords = j - i;
            if (numOfWords == 1 || j >= N)
            {
                ans.push_back(leftjustify(words, diff, i, j));
            }
            else
            {
                ans.push_back(middleJustify(words, diff, i, j));
            }
            i = j;
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    vector<string> v{"This", "is", "an", "example", "of", "text", "justification."};
    auto ans = solution.fullJustify(v, 16);
    return 0;
}