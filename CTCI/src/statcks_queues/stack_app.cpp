//
// Created by sajith on 1/21/22.
//

#include <bits/stdc++.h>

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

    virtual void Push(T data)
    {
        auto node = make_shared<Node>(data);
        node->next = this->head;
        this->head = node;
    }

    T Top() const
    {
        if (this->head) return head->data;
        throw -1;
    }

    void Pop()
    {
        head = head->next;
    }

    bool Empty()
    {

        return head == nullptr;
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


int main()
{
    Stack<int> st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40);

    cout<<st.Top()<<endl;
    st.Pop();
    cout<<st.Top()<<endl;

    MinStack mnStak;
    mnStak.Push(10);
    mnStak.Push(5);
    mnStak.Push(100);
    mnStak.Push(3);
    mnStak.Push(1000);

    MinNode mn = mnStak.Top();
    cout<<mn.minVal<<endl;

    return 0;
}

