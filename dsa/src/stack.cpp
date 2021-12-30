//
// Created by sajith on 12/29/21.
//

#include "stack.h"
#include "my_error.h"

#include <bits/stdc++.h>


void LinkedListStack::Push(int x)
{
    auto node = std::make_unique<Node>(Node(x));
    if (head == nullptr)
    {
        head = std::move(node);
        return;
    }
    node->next = std::move(head);
    head = std::move(node);
}

void LinkedListStack::Pop()
{
    if (!IsEmpty())
    {
        head = std::move(head->next);
        return;
    }
}

int LinkedListStack::Top() const
{
    if (!IsEmpty())
    {
        return head->data;
    }
    return -1;
}

bool LinkedListStack::IsEmpty() const
{
    return head == nullptr;
}


int main()
{
    using namespace std;

    Stack stck;
    stck.Push(10);
    stck.Push(20);
    stck.Push(30);
    stck.Push(40);

    cout << stck.Top() << endl;
    stck.Pop();
    cout << stck.Top() << endl;

    LinkedListStack stack2;
    stack2.Push(100);
    stack2.Push(200);
    stack2.Push(300);
    stack2.Push(400);

    cout << stack2.Top() << endl;

    stack2.Pop();
    stack2.Pop();
    stack2.Pop();
    stack2.Pop();
    stack2.Pop();

    cout << stack2.Top() << endl;
    cout << boolalpha << stack2.IsEmpty() << endl;
    return 0;
}
