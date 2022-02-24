//
// Created by sajith on 2/23/22.
//

#ifndef ADVANCED_TOPICS_BASE_H
#define ADVANCED_TOPICS_BASE_H

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val{0};
    vector<Node *> neighbors;

    Node() = default;

    explicit Node(int _val) : val{_val} {}

    Node(int _val, vector<Node *> _neighbors) : val{_val}, neighbors(move(_neighbors)) {}
};

#endif //ADVANCED_TOPICS_BASE_H
