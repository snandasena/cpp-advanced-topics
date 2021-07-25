//
// Created by sajith on 7/25/21.
//

#include<bits/stdc++.h>

using namespace std;

struct LList
{
    int val;

    LList *next{};

    LList(int val) : val{val} {}
};

void AddNode(LList **head, int val)
{
    LList *temp = *head;
    *head = new LList(val);
    (*head)->next = temp;
}

void AddNodeTail(LList **head, int val)
{
    LList *node = (*head);

    while (node->next != nullptr)
    {
        node = node->next;
    }

    node->next = new LList(val);

    node = (*head);
    (*head) = node;
}

int main()
{
    LList *llist = new LList(1);
//    AddNode(&llist, 2);
//    AddNode(&llist, 3);
//    AddNode(&llist, 4);
//    AddNode(&llist, 5);

    AddNodeTail(&llist, 2);
    AddNodeTail(&llist, 3);
    AddNodeTail(&llist, 4);
    AddNodeTail(&llist, 5);


    while (llist != nullptr)
    {
        cout << llist->val << " ";
        llist = llist->next;
    }

    cout << endl;

    return 0;
}