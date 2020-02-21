#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode* swapPairs(struct ListNode* head){

	if (head == NULL || head->next == NULL)
		return head;
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	p->next = head;
	ListNode *N_head = p;
	while (1)
	{
		ListNode *pre = p->next;
		ListNode *cur = pre->next;
		ListNode *next = cur->next;
		ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
		Node->val = pre->val;
		free(pre);
		p->next = cur;
		cur->next = Node;
		Node->next = next;
		p = Node;
		if (p->next == NULL)
			break;
		if (p->next->next == NULL)
			break;
	}
	return N_head->next;
}