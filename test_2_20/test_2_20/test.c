#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

	ListNode *cur_1 = l1;
	ListNode *cur_2 = l2;
	ListNode *cur = (ListNode*)malloc(sizeof(ListNode));
	ListNode *head = cur;
	int flag = 0;
	while (cur_1 || cur_2)
	{
		int x = cur_1 == NULL ? 0 : cur_1->val;
		int y = cur_2 == NULL ? 0 : cur_2->val;
		int num = x + y + flag;
		flag = num / 10;
		cur->next = (ListNode*)malloc(sizeof(ListNode));
		cur = cur->next;
		cur->val = num % 10;
		cur->next = NULL;
		if (cur_1 != NULL)
			cur_1 = cur_1->next;
		if (cur_2 != NULL)
			cur_2 = cur_2->next;
	}
	if (flag>0)
	{
		ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
		cur->next = Node;
		Node->val = flag;
		Node->next = NULL;
	}
	return head->next;
}