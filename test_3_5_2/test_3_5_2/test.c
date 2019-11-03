#include<stdio.h>


struct Node{
	int val;
	Node* next;
	Node* random;

};

typedef struct Node Node;
Node* copyRandomList(Node* head) {

	Node *cur = head;
	while (cur)
	{
		Node *next = cur->next;
		Node *copy = (Node*)malloc(sizeof(Node));
		copy->val = cur->val;
		copy->random = NULL;
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	cur = head;
	while (cur)
	{
		Node *next = cur->next;
		if (cur->random)
		{
			next->random = cur->random->next;
		}
		else
			next->random = NULL;
		cur = next->next;
	}
	cur = head;
	Node *copyhead = NULL;
	Node *copytail = NULL;
	while (cur)
	{
		Node *copy = cur->next;
		Node *next = copy->next;
		if (copyhead == NULL)
		{
			copyhead = copy;
			copytail = copy;
		}
		else
		{
			copytail->next = copy;
			copytail = copytail->next;
		}
		cur->next = next;
		cur = cur->next;
	}
	return copyhead;

}