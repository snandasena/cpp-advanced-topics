#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


struct BNode
{
    int data;
    BNode *link;
};

struct CharNode
{
    char data;
    CharNode *link;
};

BNode *CreateBNode(int data)
{
    BNode *node = new BNode();
    node->data = data;
    node->link = nullptr;

    return node;
}

void InsertAtTail(BNode **head, int data)
{
    BNode *newNode = CreateBNode(data);
    if (*head == nullptr)
    {
        *head = newNode;
    } else
    {
        BNode *temp = *head;
        while (temp->link != nullptr)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void InsertAtHead(BNode **head, int data)
{
    BNode *newNode = CreateBNode(data);
    newNode->link = *head;
    *head = newNode;
}


void InsertAtHead(CharNode **head, char c)
{
    CharNode *node = new CharNode();
    node->data = c;
    node->link = *head;
    *head = node;
}

int main()
{
    BNode *head = nullptr;
    InsertAtTail(&head, 1);
    InsertAtTail(&head, 2);
    InsertAtTail(&head, 3);
    InsertAtTail(&head, 4);

    while (head->link != nullptr)
    {
        cout << head->data << endl;
        head = head->link;
    }
    cout << head->data << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    BNode *head2 = nullptr;
    InsertAtHead(&head2, 1);
    InsertAtHead(&head2, 2);
    InsertAtHead(&head2, 3);
    InsertAtHead(&head2, 4);

    while (head2->link != nullptr)
    {
        cout << head2->data << endl;
        head2 = head2->link;
    }
    cout << head2->data;

    string text = "hello";
    CharNode *charNode = nullptr;
    for (char c: text)
    {
        InsertAtHead(&charNode, c);
    }
    cout << "\n" << INT_MAX << "\n" << INT_MIN << "\n";
//    cout << "\x1b[42m Hello World\n";

    vector<int> v{1, 2, 4, 5, 6, 7, 8};

    cout << endl << endl;
    for (auto i = v.rbegin(); i != v.rend(); ++i)
    {
        cout << *i << " ";
    }


    if (auto i = 10; i < 100)
    {
        std::cout << "\nHello from 'if with initialization'..\n";
    }

    cout<< (4>>1)<<endl;


    return 0;

}


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode *previous, *firstval, *secondval;
        previous = firstval = secondval = NULL;
        TreeNode *rightMost = NULL;
        TreeNode *current = root;

        while (current != NULL)
        {
            if (previous != NULL && current->val < previous->val)
            {
                if (firstval == NULL)
                    firstval = previous;

                secondval = current;
            }

            if (current->left != NULL)
            {
                rightMost = current->left;
                while (rightMost->right != NULL && rightMost->right != current)
                    rightMost = rightMost->right;

                if (rightMost->right == current)
                {
                    rightMost->right = NULL;
                    previous = current;
                    current = current->right;
                } else
                {
                    rightMost->right = current;
                    current = current->left;
                }
            } else
            {
                previous = current;
                current = current->right;
            }
        }
        swap(firstval->val, secondval->val);
    }
};