#include<stdio.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

	ListNode *cur_1 = l1;
	ListNode *cur_2 = l2;
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	ListNode *cur = head;
	int next = 0;
	while (cur_1 || cur_2)
	{

		int x = cur_1 == NULL ? 0 : cur_1->val;
		int y = cur_2 == NULL ? 0 : cur_2->val;
		int sum = x + y + next;
		next = sum / 10;
		sum %= 10;
		cur->next = (ListNode*)malloc(sizeof(ListNode));
		cur = cur->next;
		cur->next = NULL;
		cur->val = sum;
		if (cur_1)
			cur_1 = cur_1->next;
		if (cur_2)
			cur_2 = cur_2->next;
	}
	if (next)
	{
		ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
		Node->next = NULL;
		Node->val = next;
		cur->next = Node;
	}
	return head->next;
}