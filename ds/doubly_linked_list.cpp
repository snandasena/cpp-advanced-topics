#include<bits/stdc++.h>

#define el '\n'

using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *prev;
};

Node *head;
Node *GetNode(int);
void Print();
void ReversePrint();
void InsertAtHead(int);
void InsertAtTail(int);

int main()
{
  head = nullptr;
  for(int i =1; i <=10; ++i)
  {
    InsertAtHead(i);    
  }

  Print();
  ReversePrint();
  InsertAtTail(11);
  Print();
  return 0;
}

Node *GetNode(int x)
{
  Node *node = new Node;
  node->data = x;
  node->next = nullptr;
  node->prev = nullptr;
  return node;
}

void InsertAtHead(int x)
{
  Node *newNode = GetNode(x);
  if(head == nullptr)
  {
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void Print()
{
  Node *tmp = head;
  cout<<"Forward: ";
  while(tmp != nullptr)
  {
    cout<<tmp->data <<" ";
    tmp = tmp->next;
  }
  cout<<el;
}

void ReversePrint()
{
  Node *tmp = head;

  if(tmp == nullptr) return;

  // Going to last node
  while(tmp->next != nullptr)
  {
    tmp = tmp->next;
  }
  
  // Traversing backward using prev pointer
  cout<<"Reverse: ";
  while(tmp != nullptr)
  {
    cout<<tmp->data<<" ";
    tmp = tmp->prev;
  }
  cout<<el;
}

void InsertAtTail(int x)
{
  Node *tmp = head;
  Node *newNode = GetNode(x);
  
  if(head == nullptr)
  {
    head = newNode;
    return;
  }

  while(tmp->next != nullptr)
  {
    tmp = tmp->next;  
  }

  tmp->next = newNode;
  newNode->prev = tmp;
}
