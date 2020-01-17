#include<stdio.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	if (head == NULL || head->next == NULL)
		return NULL;
	ListNode *fast = head;
	ListNode *slow = head;
	ListNode *pre = NULL;
	while (n)
	{
		fast = fast->next;
		n--;
	}
	if (fast == NULL)
	{
		ListNode *Next = head->next;
		free(head);
		head = Next;
		return head;
	}
	while (fast)
	{
		pre = slow;
		fast = fast->next;
		slow = slow->next;
	}
	ListNode *next = slow->next;
	free(slow);
	slow = NULL;
	pre->next = next;
	return head;
}