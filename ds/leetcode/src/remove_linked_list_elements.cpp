//
// Created by sajith on 11/12/21.
//
//#include "base.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Node
{
    int val{0};
    shared_ptr<Node> next{nullptr};

    Node() = default;

    explicit Node(int x) : val(x) {}

    Node(int x, shared_ptr<Node> const &_next) : val(x), next(_next) {}
};


class Solution
{
public:
    static shared_ptr<Node> removeElements(shared_ptr<Node> head, int val)
    {
        while (head && head->next && head->next->val == val) head = head->next;

        auto curr = head;
        while (curr)
        {
            if (curr->next && curr->next->val == val)
            {
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};


int main()
{
    vector<int> v = {1, 2, 6, 3, 4, 5, 6};
    auto head = make_shared<Node>(v[0]);
    auto curr = head;
    for (int i = 1; i < v.size(); ++i)
    {
        auto node = make_shared<Node>(v[i]); // 10
        node->next = nullptr; // 10-> null
        curr->next = node; // null -> 10-> null
        curr = node; //  0->10-> null
    }

    Solution::removeElements(head, 6);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}