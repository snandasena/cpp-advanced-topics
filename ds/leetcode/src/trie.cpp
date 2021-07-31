//
// Created by sajith on 7/30/21.
//

#include <bits/stdc++.h>

using namespace std;

class Trie
{
    unordered_map<char, Trie *> children;
    bool isEndOfWord{false};

public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *curr = this;
        for (const char &c: word)
        {
            if (!curr->children.count(c))
            {
                curr->children[c] = new Trie;
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *curr = this;
        for (const char &c: word)
        {
            if (!curr->children.count(c))
            {
                return false;
            }
            curr = curr->children[c];
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
            if (!curr->children.count(c))
            {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};