#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* removeZeroSumSublists(struct ListNode* head){

	ListNode *pre = (ListNode*)malloc(sizeof(ListNode));
	pre->next = head;
	ListNode *p = pre;
	while (p)
	{
		int sum = 0;
		ListNode *cur = p->next;
		while (cur)
		{
			sum += cur->val;
			if (sum == 0)
			{
				p->next = cur->next;
			}
			cur = cur->next;
		}
		p = p->next;
	}
	return pre->next;
}