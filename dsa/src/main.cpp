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
    cout << "\n";
    InsertNodeAt(root, 35, 4);
    DisplayLinkedList(root);
    cout << endl;
    Node *head = new Node(0);
    InsertLinkedList(arr, 5, head);
    InsertNodeSortedLinkedList(&head, -5);
    DisplayLinkedList(head);
    InsertNodeSortedLinkedList(&head, 5);
    cout << endl;
    DisplayLinkedList(head);
    InsertNodeSortedLinkedList(&head, 60);
    cout << endl;
    DisplayLinkedList(head);
    DeleteHeadNodeFromLinkedList(&head);
    DeleteHeadNodeFromLinkedList(&head);
    cout << endl;
    DisplayLinkedList(head);
    DeleteNodeFromLinkedList(head, 5);
    cout << endl;
    DisplayLinkedList(head);
    cout << endl;
    DeleteNodeFromLinkedListData(head, 30);
    DisplayLinkedList(head);

    cout << endl << boolalpha << IsSortedLinkedList(head) << endl;
    cout << boolalpha << IsSortedLinkedList(root) << endl;

    InsertNodeSortedLinkedList(&head, 60);
    InsertNodeSortedLinkedList(&head, 60);
    InsertNodeSortedLinkedList(&head, 60);

    DisplayLinkedList(head);
    DeleteDuplicatesFromSortedLinkedList(head);
    cout << endl;
    DisplayLinkedList(head);
    ReverseLinkedListReverseLinks(&head);
    cout << endl;
    DisplayLinkedList(head);

    ReverseLinkedListRecursive(&head, nullptr, nullptr);
    cout << endl;
    DisplayLinkedList(head);
    DisplayLinkedList(root);
    cout<<endl;
}


int main()
{
    LinkedList();

    return 0;
}