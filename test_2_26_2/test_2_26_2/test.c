#include<stdio.h>

struct Node
{
	int val;
	struct Node *next;
	struct Node *prev;
	struct Node *child;
};

typedef struct Node Node;
Node* flatten(Node* head) {

	Node *cur = head;
	while (cur)
	{

		if (cur->child)
		{
			Node *next = cur->next;
			Node *cur_1 = cur->child;
			while (cur_1->next)
				cur_1 = cur_1->next;
			cur_1->next = next;
			if (next)
			{
				next->prev = cur_1;
			}
			Node *p = cur->child;
			cur->child = NULL;
			cur->next = p;
			p->prev = cur;
		}
		cur = cur->next;
	}
	return head;
}
