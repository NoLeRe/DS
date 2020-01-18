#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode* sortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *Head = (ListNode*)malloc(sizeof(ListNode));
	Head->next = head;
	head = head->next;
	Head->next->next = NULL;
	while (head)
	{
		ListNode *pre = Head;
		ListNode *cur = pre->next;
		ListNode *next = head->next;
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
		head = next;
	}
	return Head->next;
}