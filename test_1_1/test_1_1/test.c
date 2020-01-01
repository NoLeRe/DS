#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

	ListNode *fast = headA;
	ListNode *slow = headB;
	while (slow)
	{
		while (fast)
		{
			if (fast == slow)
				return slow;
			fast = fast->next;
		}
		fast = headA;
		slow = slow->next;
	}
	return NULL;
}
bool hasCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;
	ListNode *fast = head->next;
	ListNode *slow = head;
	while (slow != fast)
	{
		if (fast == NULL || fast->next == NULL)
			return false;
		slow = slow->next;
		fast = fast->next->next;
	}
	return true;
}