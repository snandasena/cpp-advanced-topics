//
// Created by sajith on 7/30/21.
//

#include <bits/stdc++.h>

using namespace std;

class WordDictionary
{
    unordered_map<char, WordDictionary *> children;
    bool isEndOfWord{false};

public:
    /** Initialize your data structure here. */
    WordDictionary() = default;

    void addWord(string word)
    {
        WordDictionary *curr = this;
        for (const char &c: word)
        {
            if (!curr->children.count(c))
            {
                curr->children[c] = new WordDictionary;
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word)
    {
        if (word.length() == 0)
        {
            return this->isEndOfWord;
        }
        WordDictionary *curr = this;

        if (curr->children.count(word[0]))
        {
            return curr->children[word[0]]->search(word.substr(1, word.length() - 1));
        } else if (word[0] == '.')
        {
            for (auto &it : curr->children)
            {
                bool find = it.second->search(word.substr(1, word.length() - 1));
                if (find)
                {
                    return true;
                }
            }
        }

        return false;
    }
};