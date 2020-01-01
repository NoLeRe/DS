#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x){

	ListNode *small = (ListNode*)malloc(sizeof(ListNode));
	ListNode *big = (ListNode*)malloc(sizeof(ListNode));
	small->next = NULL;
	big->next = NULL;
	ListNode *small_head = small;
	ListNode *big_head = big;
	ListNode *cur = head;
	while (cur)
	{
		if (cur->val<x)
		{
			ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
			Node->val = cur->val;
			Node->next = NULL;
			small->next = Node;
			small = small->next;
		}
		else
		{
			ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
			Node->val = cur->val;
			Node->next = NULL;
			big->next = Node;
			big = big->next;
		}
		cur = cur->next;
	}
	if (small_head->next)
	{
		small->next = big_head->next;
		return small_head->next;
	}
	else
		return big_head->next;
}