
//
// Created by sajith on 2/5/22.
//

#include "base.h"

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty()) return nullptr;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (unsigned i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
            {
                pq.push({lists[i]->val, i});
            }
        }

        if (pq.empty())
        {
            return nullptr;
        }
        auto *temp = new ListNode;
        auto *ans = temp;
        while (!pq.empty())
        {
            auto[val, present] = pq.top();
            pq.pop();
            temp->val = lists[present]->val;

            if (lists[present]->next)
            {
                lists[present] = lists[present]->next;
                pq.push({lists[present]->val, present});
            }

            if (pq.empty())
            {
                temp->next = nullptr;
                break;
            }

            temp->next = new ListNode;
            temp = temp->next;
        }
        return ans;
    }
};