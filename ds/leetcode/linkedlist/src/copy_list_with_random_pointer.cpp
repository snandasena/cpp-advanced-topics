//
// Created by sajith on 3/12/22.
//


#include "base.h"

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> cache;
        Node *temp = head;
        while (temp)
        {
            cache[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while (temp)
        {
            cache[temp]->next = cache[temp->next];
            cache[temp]->random = cache[temp->random];
            temp = temp->next;
        }
        return cache[head];
    }
};
