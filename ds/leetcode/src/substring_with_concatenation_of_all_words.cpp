//
// Created by sajith on 6/14/21.
//

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {

        int wordLength = words[0].length();
        int numberOfWords = words.size();
        vector<int> resultIndices;

        unordered_map<string, int> wordBankMap;
        for (auto const &str:  words)
        {
            if (wordBankMap.find(str) == wordBankMap.end())
            {
                wordBankMap[str] = 1;
            }
            else
            {
                wordBankMap[str]++;
            }
        }

        if (wordLength * numberOfWords > s.length())
        {
            return resultIndices;
        }

        for (int i = 0; i <= s.length() - (numberOfWords * wordLength); ++i)
        {
            unordered_map<string, int> wordsUsedMap;

            for (int j = i; j < i + (numberOfWords * wordLength); j += wordLength)
            {
                if (wordBankMap.find(s.substr(j, wordLength)) == wordBankMap.end())
                {
                    break;
                }
                else if (wordsUsedMap.find(s.substr(j, wordLength)) == wordsUsedMap.end())
                {
                    wordsUsedMap[s.substr(j, wordLength)] = 1;
                }
                else
                {
                    wordsUsedMap[s.substr(j, wordLength)]++;
                    if (wordsUsedMap[s.substr(j, wordLength)] > wordBankMap[s.substr(j, wordLength)])
                    {
                        break;
                    }
                }
            }

            if (wordsUsedMap == wordBankMap)
            {
                resultIndices.emplace_back(i);
            }
        }

        return resultIndices;
    }
};

int main()
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    Solution solution;
    vector<int> res = solution.findSubstring(s, words);
    for (auto const &i: res)
    {
        cout << i << " ";
    }


    return 0;
}