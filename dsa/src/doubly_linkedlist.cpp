//
// Created by sajith on 12/28/21.
//

#include "doubly_linkedlist.h"

void DoublyLL(Node *head)
{
    InsertAtHead(10, &head);
    InsertAtHead(20, &head);
    InsertAtHead(30, &head);
    InsertAtHead(40, &head);
    InsertAtHead(50, &head);

    Print(head);
    ReversePrint(head);
}

int main()
{
    Node *head = nullptr;
    DoublyLL(head);
    return 0;
}