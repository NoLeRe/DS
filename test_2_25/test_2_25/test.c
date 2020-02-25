#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


#define pop(stack, top) ((stack)[(top)--])
#define push(stack, top, val) ( (stack)[++(top)] = (val) )
typedef struct ListNode ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

	ListNode *st_1[1000], *st_2[1000];
	ListNode **Long, **Short;
	ListNode *p, *q;
	int Top_1 = -1, Top_2 = -1;
	int L_top, S_top;
	for (ListNode *tmp = l1; tmp; tmp = tmp->next)
		push(st_1, Top_1, tmp);
	for (ListNode *tmp = l2; tmp; tmp = tmp->next)
		push(st_2, Top_2, tmp);
	if (Top_1>Top_2)
	{
		Long = st_1;
		L_top = Top_1;
		Short = st_2;
		S_top = Top_2;
	}
	else
	{
		Long = st_2;
		L_top = Top_2;
		Short = st_1;
		S_top = Top_1;
	}
	ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
	Node->val = 0;
	int next = 0;
	while (L_top != -1)
	{
		p = pop(Long, L_top);
		q = S_top == -1 ? Node : pop(Short, S_top);
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