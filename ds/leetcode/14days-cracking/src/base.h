//
// Created by sajith on 9/20/21.
//

#ifndef ADVANCED_TOPICS_BASE_H
#define ADVANCED_TOPICS_BASE_H

#include <bits/stdc++.h>
#define LOG(x) cout<<x<<endl

using namespace std;



struct Node
{
    int val;
    Node *next;

    Node() : val(0), next(nullptr) {}

    Node(int x) : val(x), next(nullptr) {}

    Node(int x, Node *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//class Node
//{
//public:
//    int val;
//    Node *left;
//    Node *right;
//    Node *next;
//
//    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//
//    Node(int _val, Node *_left, Node *_right, Node *_next)
//        : val(_val), left(_left), right(_right), next(_next) {}
//};




struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif //ADVANCED_TOPICS_BASE_H
