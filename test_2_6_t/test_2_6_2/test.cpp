#include<stdio.h>
#include<stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

bool chkPalindrome(ListNode* A) {
	if (A == NULL || A->next == NULL)
		return true;
	ListNode *fast = A;
	ListNode *slow = A;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *Next = NULL;
	ListNode *prev = NULL;
	while (A != slow)
	{
		Next = A->next;
		A->next = prev;
		prev = A;
		A = Next;
	}
	if (fast&&fast->next == NULL)
		slow = slow->next;
	while (slow)
	{
		if (prev->val != slow->val)
			return false;
		prev = prev->next;
		slow = slow->next;
	}
	return true;
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