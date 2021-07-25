#include<iostream>

using namespace std;

class Node
{
  public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b)
{
  return (a>b)? a:b;
}


