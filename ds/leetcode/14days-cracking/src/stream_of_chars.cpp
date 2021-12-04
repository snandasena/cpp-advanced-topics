//
// Created by sajith on 12/4/21.
//

#include "base.h"

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
    void insert(string const &word)
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
    bool search(string const &word)
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
    bool startsWith(string const &prefix)
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

    bool search(deque<char> const &str)
    {
        Trie *curr = this;
        for (const char &c: str)
        {
            if (!curr->children.count(c))
            {
                return false;
            }
            curr = curr->children[c];
            if(curr->isEndOfWord) return true;
        }
        return false;
    }
};

class StreamChecker
{
    Trie root;
    deque<char> word;
public:
    StreamChecker(vector<string> &words)
    {
        for (auto &str: words)
        {
            reverse(str.begin(), str.end());
            root.insert(str);
        }
    }

    bool query(char letter)
    {
        word.push_front(letter);
        return root.search(word);
    }
};
