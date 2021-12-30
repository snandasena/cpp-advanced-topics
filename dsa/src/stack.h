//
// Created by sajith on 12/29/21.
//

#ifndef ADVANCED_TOPICS_STACK_H
#define ADVANCED_TOPICS_STACK_H

#include <bits/stdc++.h>

#define MX  100

class Stack
{

    int arr[MX];
    int top{-1};
public:
    Stack() = default;

    void Push(int x)
    {
        if (top > MX) throw std::runtime_error{"EOOR"};
        top += 1;
        arr[top] = x;
    }

    void Pop()
    {
        if (top < 0) throw std::runtime_error{"EOOR"};;
        top -= 1;
    }

    int Top()
    {
        return arr[top];
    }

    bool IsEmpty()
    {
        return top != -1;
    }
};

class LinkedListStack
{
    struct Node
    {
        int data{};
        std::unique_ptr<Node> next{};

        Node() = default;

        explicit Node(int x) : data{x} {}
    };

    std::unique_ptr<Node> head{nullptr};

public:
    LinkedListStack() = default;

    void Push(int x);
    void Pop();
    int Top() const;
    bool IsEmpty() const;
};


#endif //ADVANCED_TOPICS_STACK_H
