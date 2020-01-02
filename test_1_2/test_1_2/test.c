#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head){

	if (head == NULL || head->next == NULL)
		return head;
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->next = head;
	head = head->next;
	node->next->next = NULL;
	while (head)
	{
		ListNode *pre = node;
		ListNode *cur = node->next;
		ListNode *Nexthead = head->next;
		while (cur)
		{
			if (cur->val>head->val)
			{
				pre->next = head;
				head->next = cur;
				break;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
		if (cur == NULL)
		{
			pre->next = head;
			head->next = NULL;
		}
		head = Nexthead;
	}
	return node->next;
}
ListNode* deleteDuplication(ListNode* pHead)
{

	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
	Node->next = NULL;
	ListNode *pre = Node;
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
	return Node->next;
}