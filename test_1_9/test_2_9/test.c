#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x){

	ListNode *cur = head;
	ListNode *Small_Head = (ListNode*)malloc(sizeof(ListNode));
	ListNode *Big_Head = (ListNode*)malloc(sizeof(ListNode));
	Small_Head->next = NULL;
	Big_Head->next = NULL;
	ListNode *cur_small = Small_Head;
	ListNode *cur_big = Big_Head;
	while (cur)
	{
		ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
		Node->val = cur->val;
		Node->next = NULL;
		if (cur->val<x)
		{
			cur_small->next = Node;
			cur_small = Node;
		}
		else
		{
			cur_big->next = Node;
			cur_big = Node;
		}
		cur = cur->next;
	}
	cur_small->next = Big_Head->next;
	return Small_Head->next;
}