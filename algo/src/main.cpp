#include "algo.h"

using namespace std;

int main()
{
	Node *head = new Node(10);
	InsertNode(&head, 20);
	InsertNode(&head, 30);
	InsertNode(&head, 40);
	InsertNode(&head, 50);

	InsertToTail(head, 60);
	InsertToTail(head,70);
		
	while(head)
	{
		cout<< head->data<<endl;
		head = head->next;
	}	
	
	return 0;
}
