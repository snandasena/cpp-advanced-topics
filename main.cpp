#include <iostream>
#include <vector>

using namespace std;


struct Node
{
    int data;
    Node *link;
};

struct CharNode
{
    char data;
    CharNode *link;
};

Node *CreateNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->link = nullptr;

    return node;
}

void InsertAtTail(Node **head, int data)
{
    Node *newNode = CreateNode(data);
    if (*head == nullptr)
    {
        *head = newNode;
    } else
    {
        Node *temp = *head;
        while (temp->link != nullptr)
        {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

void InsertAtHead(Node **head, int data)
{
    Node *newNode = CreateNode(data);
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
    Node *head = nullptr;
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

    Node *head2 = nullptr;
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



    return 0;

}