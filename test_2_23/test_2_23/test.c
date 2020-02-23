#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
void reorderList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *cur = head;
	while (cur->next&&cur->next->next)
	{
		ListNode *tail = head;
		ListNode *pre = NULL;
		ListNode *next = NULL;
		while (tail->next)
		{
			pre = tail;
			tail = tail->next;
			next = tail->next;
		}
		tail->next = cur->next;
		cur->next = tail;
		pre->next = next;
		cur = cur->next->next;
	}
	return head;
}