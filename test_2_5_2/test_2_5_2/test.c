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
	ListNode *small_head = small;
	ListNode *big_head = big;
	ListNode *cur = pHead;
	while (cur)
	{
		if (cur->val<x)
		{
			if (small == NULL)
			{
				small = cur;
				small_head = small;
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
				big_head = big;
			}
			else
			{
				big->next = cur;
				big = big->next;
			}
		}
		cur = cur->next;
	}
	if (small_head != NULL)
	{
		if (big_head != NULL)
		{
			small->next = big_head;
			big->next = NULL;
		}
		return small_head;
	}
	else
		return big_head;
}
