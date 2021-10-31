//
// Created by sajith on 10/30/21.
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
    int insert(string word)
    {
        Trie *curr = this;
        int count = 0;
        for (const char &c: word)
        {
            if (!curr->children.count(c))
            {
                curr->children[c] = new Trie;
            } else
            {
                ++count;
            }
            curr = curr->children[c];
        }
        curr->isEndOfWord = true;
        return count;
    }
};

class Solution
{
public:
    int prime = 10000001;
    vector<int> power;

    string rabinKarp(string &s, int len)
    {
        if (len == 0) return "";
        int n = s.length();
        int curr = 0;
        unordered_map<int, vector<int>> hash;

        for (const char &c: s)
        {
            curr = (curr * 26 + (c - 'a')) % prime;
        }
        hash[curr] = {0};

        for (int i = len; i < n; ++i)
        {
            curr = ((curr - power[len - 1] * (s[i - len] - 'a')) % prime + prime) % prime;
            curr = (curr * 26 + (s[i] - 'a')) % prime;

            if (hash.find(curr) == hash.end())
            {
                hash[curr] = {i - len + 1};
            } else
            {
                for (const int &idx : hash[curr])
                {
                    string str = s.substr(i - len + 1, len);
                    if (s.substr(idx, len) == str)
                    {
                        return s.substr(idx, len);
                    }
                }
                hash[curr].push_back({i - len + 1});
            }
        }

        return "";
    }

    string longestDupSubstring(string s)
    {
        int n = s.length();
        int l = 0, r = n - 1, mid;
        power = vector<int>(n);
        power[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            power[i] = (power[i - 1] * 26) % prime;
        }

        string res;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            string curr = rabinKarp(s, mid);

            if (curr.length() > res.length())
            {
                res = curr;
                l = ++mid;
            } else
            {
                r = --mid;
            }
        }
        return res;
    }

    string longestDupSubstring1(string s)
    {
        Trie trie;
        int mx = 0;
        int mxIdx = 0;

        for (int i = 0; i < s.length(); ++i)
        {
            int cnt = trie.insert(s.substr(i));
            if (cnt > mx)
            {
                mx = cnt;
                mxIdx = i;
            }
        }
        return s.substr(mxIdx, mx);
    }
};