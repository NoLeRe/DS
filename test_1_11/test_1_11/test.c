#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* reverseBetween(struct ListNode* head, int m, int n){

	ListNode *Head = (ListNode*)malloc(sizeof(ListNode));
	Head->next = head;
	ListNode *pre = Head;
	ListNode *one = NULL;
	ListNode *two = NULL;
	ListNode *next = NULL;
	ListNode *cur = head;
	int i = 1;
	while (cur&&i <= n)
	{
		next = cur->next;
		if (i == m)
		{
			one = pre;
		}
		if (i == n)
		{
			two = cur;
		}
		if (i>m&&i <= n)
		{
			cur->next = pre;
		}
		pre = cur;
		cur = next;
		i++;
	}
	one->next->next = next;
	one->next = two;
	return Head->next;
}