#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)


 
 struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
	cur = node;
	while (l1&&l2)
	{
		if (l1->val<l2->val)
		{
			node->next = l1;
			l1 = l1->next;
		}
		else
		{
			node->next = l2;
			l2 = l2->next;
		}
		node = node->next;
	}
	if (l1 != NULL)
	{
		node->next = l1;
	}
	else if (l2 != NULL)
	{
		node->next = l2;
	}
	else
	{
		return NULL;
	}
	return cur->next;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

	ListNode *slow = pListHead;
	ListNode *fast = pListHead;
	if (pListHead == NULL)
	{
		return NULL;
	}
	while (k&&fast != NULL)
	{
		fast = fast->next;
		k--;
	}
	if (k>0 && fast == NULL)
	{
		return NULL;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}