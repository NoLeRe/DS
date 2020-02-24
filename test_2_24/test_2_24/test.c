#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* oddEvenList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *pre = head;
	ListNode *cur = pre->next;
	while (cur&&cur->next)
	{
		ListNode *next = cur->next;
		cur->next = next->next;
		next->next = pre->next;
		pre->next = next;
		pre = pre->next;
		cur = cur->next;
	}
	return head;
}

#define pop(stack, top) ((stack)[(top)--])
#define push(stack, top, val) ( (stack)[++(top)] = (val) )

typedef struct ListNode ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

	ListNode *st1[1000];
	ListNode *st2[1000];
	ListNode **small, **big;
	ListNode *p, *q;
	int top_1 = -1, top_2 = -1;
	int stop, btop;
	for (ListNode *tmp = l1; tmp; tmp = tmp->next)
	{
		push(st1, top_1, tmp);
	}
	for (ListNode *tmp = l2; tmp; tmp = tmp->next)
	{
		push(st2, top_2, tmp);
	}
	if (top_1>top_2)
	{
		big = st1;
		btop = top_1;
		small = st2;
		stop = top_2;
	}
	else
	{
		big = st2;
		btop = top_2;
		small = st1;
		stop = top_1;
	}
	ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
	Node->val = 0;
	int next = 0;
	while (btop != -1)
	{
		p = pop(big, btop);
		q = stop == -1 ? Node : pop(small, stop);
		p->val += q->val + next;
		next = p->val / 10;
		p->val %= 10;
	}
	if (next)
	{
		Node->val = 1;
		Node->next = p;
		return Node;
	}
	free(Node);
	return p;
}