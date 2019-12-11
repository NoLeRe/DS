#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

struct ListNode
{
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode* partition(ListNode* pHead, int x) 
{
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
				smallhead = small;
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
				bighead = big;
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
		if (big != NULL)
		{
			big->next = NULL;
		}
		return smallhead;
	}
	else
	{
		return bighead;
	}
}

bool chkPalindrome(ListNode* A) {
	// write code here
	ListNode *cur = A;
	ListNode *node = NULL;

	while (cur)
	{
		ListNode *head = (ListNode*)malloc(sizeof(ListNode));
		head->val = cur->val;
		head->next = NULL;
		if (node == NULL)
		{
			node = head;
			node->next = NULL;
		}
		else
		{
			head->next = node;
			node = head;
		}
		cur = cur->next;
	}
	while (A&&node)
	{
		if (A->val != node->val)
		{
			return false;
		}
		A = A->next;
		node = node->next;
	}
	return true;

}