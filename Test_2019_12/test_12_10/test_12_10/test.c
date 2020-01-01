#include<stdio.h>
#include<stdlib.h>


struct ListNode {
int val;
struct ListNode *next;
};

typedef struct ListNode ListNode;
ListNode* partition(ListNode* pHead, int x) {

	ListNode *small = NULL;
	ListNode *big = NULL;
	ListNode *smallhead = small;
	ListNode *bighead = big;
	ListNode *cur = pHead;
	while (cur)
	{
		if (cur->val<x)
		{
			if (small == NULL)
			{
				small = cur;
			}
			else
			{
				small->next = cur;
				small = small->next;
			}
		}
		else
		{
			if (big == NULL)
			{
				big = cur;
			}
			else
			{
				big->next = cur;
				big = big->next;
			}
		}
		cur = cur->next;
	}
	if (small != NULL)
	{
		small->next = bighead;
	}
	if (big != NULL)
	{
		big->next = NULL;
	}
	if (smallhead != NULL)
	{
		return smallhead;
	}
	else
	{
		return big;
	}
}