//
// Created by sajith on 11/4/22.
//
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <list>
#include <unordered_map>

using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val)
    {};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val)
    {};
};

class Cache
{

protected:
    map<int, Node *> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node *tail; // double linked list tail pointer
    Node *head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};

class LRUCache : public Cache
{
    void push_front(int key, int val)
    {
        auto *node = new Node{nullptr, head, key, val};
        if (head == nullptr)
        {
            tail = node;
        }
        mp[key] = head = node;
    }
    void pop_back(Node *curr)
    {
        auto *prev = curr->prev;
        auto *next = curr->next;

        if (prev != nullptr)
        {
            prev->next = next;
        }
        if (next != nullptr)
        {
            next->prev = prev;
        }

        delete curr;
    }
public:
    LRUCache(int c)
    {
        this->cp = c;
        this->tail = nullptr;
        this->head = nullptr;
    }

    void set(int key, int val) override
    {
        if (mp.find(key) == mp.end())
        {
            if (mp.size() == cp)
            {
                auto k = tail->key;
                auto *prev = tail->prev;
                pop_back(tail);
                tail = prev;
                mp.erase(k);
            }
            push_front(key, val);
            mp[key] = head;
        }
        else
        {
            auto *node = mp.find(key)->second;
            node->value = val;
        }
    }

    int get(int key) override
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        else
        {
            auto *node = mp.find(key)->second;
            auto k = node->key;
            auto v = node->value;
            pop_back(node);
            push_front(k, v);
            return v;
        }
    }
};


int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
