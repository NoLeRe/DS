#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;

ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return pHead;

	ListNode *NodeHead = (ListNode*)malloc(sizeof(ListNode));
	NodeHead->next = NULL;
	ListNode *pre = NodeHead;
	ListNode *cur = pHead;
	while (cur)
	{
		if (cur->next&&cur->val == cur->next->val)
		{
			while (cur->next&&cur->val == cur->next->val)
			{
				cur = cur->next;
			}
			cur = cur->next;
			pre->next = cur;
		}
		else
		{
			pre->next = cur;
			cur = cur->next;
			pre = pre->next;
		}
	}
	return NodeHead->next;
}