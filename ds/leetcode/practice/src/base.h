//
// Created by sajith on 7/2/22.
//

#ifndef ADVANCED_TOPICS_BASE_H
#define ADVANCED_TOPICS_BASE_H

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {}
    ListNode(int x) : val(x), next(nullptr)
    {}
    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};

#endif //ADVANCED_TOPICS_BASE_H
