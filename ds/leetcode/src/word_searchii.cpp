//
// Created by sajith on 11/2/21.
//

#include "base.h"

class Trie
{
public:
    unordered_map<char, Trie *> child;
    bool isEnd{false};
    Trie() = default;

    ~Trie()
    {
        for (auto &it : child)
        {
            delete it.second;
        }
    }

    void insert(const string &word)
    {
        Trie *curr = this;
        for (const char &c: word)
        {
            if (curr->child.count(c) == 0)
            {
                curr->child[c] = new Trie;
            }
            curr = curr->child[c];
        }
        curr->isEnd = true;
    }

    bool search(const string &word)
    {
        Trie *curr = this;
        for (const char &c: word)
        {
            if (curr->child.count(c) == 0)
            {
                return false;
            }
            curr = curr->child[c];
        }
        if (curr->isEnd) return true;
        return false;
    }
};

class Solution
{
    unordered_set<string> res;

    void dfs(vector<vector<char>> &board, int i, int j, Trie *trie, const string &str)
    {
        char c = board[i][j];
        if (c == '$') return;
        board[i][j] = '$';
        Trie *t = trie->child[c];
        if (t)
        {
            string ss = str + c;
            if (t->isEnd) res.insert(ss);

            if (i < board.size() - 1) dfs(board, i + 1, j, t, ss);
            if (i > 0) dfs(board, i - 1, j, t, ss);
            if (j < board[0].size() - 1) dfs(board, i, j + 1, t, ss);
            if (j > 0) dfs(board, i, j - 1, t, ss);
        }
        board[i][j] = c;
    }

public:
    vector<string> findWords2(vector<vector<char>> &board, vector<string> &words)
    {
        Trie trie;
        for (auto &s: words) trie.insert(s);
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                dfs(board, i, j, &trie, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }

};


int main()
{
    vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
                                  {'e', 't', 'a', 'e'},
                                  {'i', 'h', 'k', 'r'},
                                  {'i', 'f', 'l', 'v'}};

    vector<string> words = {"oath", "pea", "eat", "rain"};

    Solution solution;
    auto res = solution.findWords(board, words);
    return 0;
}