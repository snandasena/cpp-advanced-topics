//
// Created by sajith on 1/10/22.
//
#include <bits/stdc++.h>

using namespace std;

class Node
{
    int data;
    Node *next{nullptr};
public:
    Node() = default;

    explicit Node(int d) : data{d} {}

    friend class LinkedList;
};

class LinkedList
{
    Node *head{nullptr};

public:
    LinkedList() = default;

    explicit LinkedList(Node *h) : head{h} {};

    void InsertToHead(int data)
    {
        Node *node = new Node(data);
        if (head == nullptr)
        {
            head = node;
            return;
        }
        node->next = head;
        head = node;
    }

    void InsertToTail(int data)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        Node *node = new Node(data);
        temp->next = node;
    }

    void PrintAll()
    {
        Node *node = head;
        while (node)
        {
            cout << node->data << '\t';
            node = node->next;
        }
        cout << '\n';
    }

    void DeleteNode(int key)
    {
        Node *node = head;
        Node *prev;
        while (node->next != nullptr)
        {
            prev = node;
            if (node->next->data == key)
            {
                Node *temp = node->next;
                prev->next = node->next->next;
                delete temp;
            }
            node = node->next;
        }
    }

    void DeleteDuplicatesNodes()
    {
        set<int> cache;
        Node *node = head;
        Node *prev;
        while (node != nullptr)
        {
            if (cache.count(node->data) > 0)
            {
                Node *temp = node;
                assert(prev != nullptr);
                prev->next = node->next;
                node = node->next;
                delete temp;
            }
            else
            {
                cache.insert(node->data);
                prev = node;
                node = node->next;
            }
        }
    }

    void DeleteDuplicateNodes2()
    {
        Node *node = head;
        while (node != nullptr)
        {
            Node *curr = node;
            while (curr->next != nullptr)
            {
                if (node->data == curr->next->data)
                {
                    Node *temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                }
                else
                {
                    curr = curr->next;
                }
            }
            node = node->next;
        }
    }

    // Don't return the element
    int Helper(Node *node, int k)
    {
        if (node == nullptr) return 0;
        int indx = Helper(node->next, k) + 1;
        if (indx == k)
        {
            cout << "Kth to the last element is " << node->data << endl;
        }
        return indx;
    }


    Node *KthToLastElement(Node *node, int k, int &index)
    {
        if (node == nullptr) return nullptr;

        Node *curr = KthToLastElement(node->next, k, index);
        index += 1;

        if (index == k)
        {
            return node;
        }
        return curr;
    }

    void PrintKthLastElement(int k)
    {
        Node *node = head;
        Helper(node, k);
    }

    void PrintKthLastNode(int k)
    {
        int i = 0;
        Node *node = head;
        Node *ans = KthToLastElement(node, k, i);

        cout << "Kth to last element is " << ans->data << endl;
    }

    // O(1) space approach
    Node *KthToLastLementBest(int k)
    {
        Node *n1 = head;
        Node *n2 = head;

        for (int i = 0; i < k; ++i)
        {
            if (n1 == nullptr) return nullptr;
            n1 = n1->next;
        }

        while (n1)
        {
            n1 = n1->next;
            n2 = n2->next;
        }

        return n2;
    }

    void KthToLastEle(int k)
    {
        Node *node = KthToLastLementBest(k);
        cout << "Kth to the last element is " << node->data << endl;
    }

    bool DeleteMidNode(Node *mid)
    {
        if (mid == nullptr || mid->next == nullptr) return false;
        Node *next = mid->next;
        mid->data = next->data;
        mid->next = next->next;
        return true;
    }

    void DelMid()
    {
        Node *mid = head;
        Node *fast = head;
        while (fast->next)
        {
            mid = mid->next;
            fast = fast->next->next;
        }

        cout << boolalpha << DeleteMidNode(mid) << endl;
    }

    Node *PartitionHelper(Node *node, int val)
    {
        Node *h = node;
        Node *t = node;
        Node *next;
        while (node)
        {
            next = node->next;
            if (node->data < val)
            {
                node->next = h;
                h = node;
            }
            else
            {
                t->next = node;
                t = node;
            }
            node = next;
        }
        if (t)
        {
            t->next = nullptr;
        }
        return h;
    }

    void PrintListNode(Node *node)
    {
        while (node)
        {
            cout << node->data << '\t';
            node = node->next;
        }
        cout << '\n';
    }

    void Partition(int val)
    {
        Node *node = head;
        node = PartitionHelper(node, val);
        PrintListNode(node);
    }

    int SumLists()
    {
        Node *n1 = head;
        int i = 1;
        int res = 0;

        while (n1)
        {
            res = res + n1->data * i;
            i *= 10;
            n1 = n1->next;
        }
        return res;
    }
};

struct ListNode
{
    int data;
    ListNode *next{nullptr};

    ListNode() = default;

    explicit ListNode(int d) : data{d} {}

};

ListNode *SumListNodesHelper(ListNode *n1, ListNode *n2, int carry)
{
    if (n1 == nullptr && n2 == nullptr && carry == 0) return 0;

    ListNode *res;
    int value = carry;

    if (n1)
    {
        value += n1->data;
    }

    if (n2)
    {
        value += n2->data;
    }
}

ListNode *SumLists(ListNode *n1, ListNode *n2)
{

}


int main()
{
    LinkedList ll;
    ll.InsertToHead(10);
    ll.InsertToHead(10);
    ll.InsertToHead(10);
    ll.InsertToHead(10);
    ll.InsertToHead(20);
    ll.InsertToTail(200);
    ll.InsertToTail(300);
    ll.InsertToTail(400);
    ll.InsertToTail(500);

    ll.PrintAll();

    ll.DeleteNode(200);

    ll.PrintAll();
//    ll.DeleteDuplicatesNodes();
    ll.DeleteDuplicateNodes2();
    ll.PrintAll();
    ll.InsertToTail(600);
    ll.InsertToTail(700);
    ll.InsertToTail(800);
    ll.InsertToTail(100);
    ll.InsertToTail(100);
    ll.InsertToTail(100);
    ll.InsertToTail(100);
    ll.InsertToTail(5);
    ll.InsertToTail(5);
    ll.InsertToTail(10);
    ll.PrintAll();
    ll.PrintKthLastElement(3);
    ll.PrintKthLastNode(3);
    ll.KthToLastEle(3);
    ll.DelMid();
    ll.PrintAll();
//
    ll.Partition(100);

    LinkedList l1;
    l1.InsertToHead(6);
    l1.InsertToHead(1);
    l1.InsertToHead(7);

    l1.PrintAll();

    int res = l1.SumLists();

    LinkedList l2;
    l2.InsertToHead(2);
    l2.InsertToHead(9);
    l2.InsertToHead(5);
    l2.PrintAll();

    res += l2.SumLists();

    cout << res << endl;
    return 0;
}
