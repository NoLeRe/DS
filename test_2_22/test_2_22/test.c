#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* rotateRight(struct ListNode* head, int k){
	if (head == NULL || head->next == NULL)
		return head;
	int len = 1;
	ListNode *cur = head;
	while (cur->next)
	{
		cur = cur->next;
		len++;
	}
	k %= len;
	while (k--)
	{
		ListNode *pre = NULL;
		ListNode *tail = head;
		while (tail->next)
		{
			pre = tail;
			tail = tail->next;
		}
		ListNode *next = tail->next;
		tail->next = head;
		head = tail;
		pre->next = next;
	}
	return head;
}