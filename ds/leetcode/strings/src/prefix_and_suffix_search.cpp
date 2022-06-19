//
// Created by sajith on 6/18/22.
//
#include "base.h"


struct TrieNode;

struct TrieNode
{
    unordered_map<int, TrieNode *> children;
    int weight = 0;
};

class WordFilter
{
public:
    WordFilter(vector<string> &words)
    {

    }

    int f(string prefix, string suffix)
    {

    }
};


int main()
{
    return 0;
}