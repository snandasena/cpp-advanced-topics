//
// Created by sajith on 11/9/21.
//

#include "base.h"


class Solution
{
    int bmask;

    int bitMask(const string &word)
    {
        bmask = 0;
        for (const char &c: word)
        {
            bmask |= 1 << (c - 'a');
        }
        return bmask;
    }

public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        unordered_map<int, int> wordCount;
        for (string &str: words)
        {
            wordCount[bitMask(str)]++;
        }

        vector<int> res;
        int first, cont, mask;
        for (string &puz: puzzles)
        {
            first = 1 << (puz[0] - 'a');
            cont = wordCount[first];

            mask = bitMask(puz.substr(1));
            for (int submask = mask; submask; submask = (submask - 1) & mask)
            {
                cont += wordCount[submask | first];
            }
            res.push_back(cont);
        }
        return res;
    }
};

int main()
{
    vector<string> words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    vector<string> puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};

    Solution solution;
    solution.findNumOfValidWords(words, puzzles);
    return 0;
}