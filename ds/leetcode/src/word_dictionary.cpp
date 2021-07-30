//
// Created by sajith on 7/30/21.
//

#include <bits/stdc++.h>

using namespace std;

class Trie
{
    vector<Trie *> children;
    bool isEndOfWord;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        children.assign(26, nullptr);
        isEndOfWord = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *curr = this;
        for (const char &c: word)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                curr->children[c - 'a'] = new Trie;
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *curr = this;
        for (const char &c: word)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->children[c - 'a'];
        }
        if (curr->isEndOfWord)
        {
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *curr = this;
        for (const char &c: prefix)
        {
            if (curr->children[c - 'a'] == nullptr)
            {
                return false;
            }
            curr = curr->children[c - 'a'];
        }

        return true;
    }
};