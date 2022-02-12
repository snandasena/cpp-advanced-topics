//
// Created by sajith on 2/12/22.
//

#include "base.h"

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> word_set;
        bool isPresent = false;
        for (auto &word: wordList)
        {
            if (endWord == word)
            {
                isPresent = true;
            }
            word_set.insert(move(word));
        }
        if (!isPresent) return 0;

        queue<string> que;
        que.push(beginWord);
        int depth = 0;
        size_t lsize;
        string curr{};
        string temp{};
        while (!que.empty())
        {
            depth += 1;
            lsize = que.size();
            while (lsize--)
            {
                curr = que.front();
                que.pop();
                for (size_t i = 0; i < curr.length(); ++i)
                {
                    temp = curr;
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        temp[i] = c;
                        if (curr == temp) continue;
                        if (temp == endWord) return depth + 1;

                        if (word_set.find(temp) != word_set.end())
                        {
                            que.push(temp);
                            word_set.erase(temp);
                        }
                    }

                }
            }
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<string> wordlist{"hot", "dot", "dog", "lot", "log", "cog"};
    string beginw{"hit"};
    string endw{"cog"};

    cout << solution.ladderLength(beginw, endw, wordlist) << endl;

    return 0;
}