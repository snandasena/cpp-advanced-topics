//
// Created by sajith on 1/21/22.
//

#include <bits/stdc++.h>

#define LOG(x) cout<<x<<endl

using namespace std;

template<typename T>
class Stack
{
    struct Node
    {
        shared_ptr<Node> next{nullptr};
        T data;

        explicit Node(T d) : data{d} {}
    };

    shared_ptr<Node> head{nullptr};
public:

    Stack() = default;

    virtual ~Stack() = default;

    virtual void Push(T data)
    {
        auto node = make_shared<Node>(data);
        node->next = this->head;
        this->head = node;
    }

    virtual void Pop()
    {
        head = head->next;
    }

    bool Empty()
    {

        return head == nullptr;
    }

    T Top() const
    {
        if (this->head) return head->data;
        throw -1;
    }
};

struct MinNode
{
    int data;
    int minVal;

};

class MinStack : public Stack<MinNode>
{
public:

    MinStack() = default;

    void Push(int data)
    {
        int mn = min(data, MinVal());
        Stack<MinNode>::Push(MinNode{data, mn});
    }

    int MinVal()
    {
        if (this->Empty())
        {
            return INT_MAX;
        }
        else
        {
            return Top().minVal;
        }
    }
};

template<typename T, typename S = size_t>
class CapacityStack : public Stack<T>
{
    S size{10};
    S capacity = 0;
public:

    CapacityStack() = default;

    explicit CapacityStack(S s) : size{s} {}

    void Push(T data) override
    {
        if (!IsFull())
        {
            Stack<T>::Push(data);
            ++capacity;
        }
        else
        {
            throw -1;
        }
    }

    void Pop() override
    {
        if (Stack<T>::Empty())
        {

            throw -1;
        }
        else
        {
            Stack<T>::Pop();
            --capacity;
        }
    }

    bool IsFull()
    {
        return capacity == size;
    }
};

class MyQueue
{
    stack<int> stackNewest;
    stack<int> stackOldest;

    MyQueue() = default;

    int size()
    {
        return stackNewest.size() + stackOldest.size();
    }
};

int main()
{
    Stack<int> st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);

    LOG(st.Top());
    st.Pop();
    LOG(st.Top());

    MinStack mnStak;
    mnStak.Push(10);
    mnStak.Push(5);
    mnStak.Push(100);
    mnStak.Push(3);
    mnStak.Push(1000);

    MinNode mn = mnStak.Top();
    LOG (mn.minVal);


    CapacityStack<int> capaStack;
    capaStack.Push(10);
    capaStack.Push(20);
    capaStack.Push(30);
    capaStack.Push(40);
    capaStack.Pop();

    LOG(capaStack.Top());
    return 0;
}

