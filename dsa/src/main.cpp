//
// Created by sajith on 10/27/21.
//

#include "linked_list.h"

void LinkedList()
{
    using namespace dsa;

    Node *root = new Node(0);
    int arr[] = {10, 20, 30, 40, 50};
    InsertLinkedList(arr, 5, root);
    DisplayLinkedList(root);
    cout << endl;
    DisplayLinkedListRecursive(root);
    cout << endl;
    DisplayLinkedListRecursiveReverse(root);
    cout << "\nNode count: " << CountNodesInLinkedList(root);
    cout << "\nSum of all nodes : " << AddValuesInLinkedList(root);
    cout << "\nMax of linked list : " << FindMaxValueOfLinkedList(root);
    cout << "\nMax of linked list : " << FindMaxValueOfLinkedListRecursive(root);
    Node *res = LinearSearch(root, 40);
    cout << "\n" << res->data;
    res = LinerSearchRecursive(root, 40);
    cout << "\n" << res->data << endl;
    InsertNodeHead(&root, 60);
    DisplayLinkedList(root);
    cout<<"\n";
    InsertNodeAt(root, 35, 4);
    DisplayLinkedList(root);
}


int main()
{
    LinkedList();

    return 0;
}