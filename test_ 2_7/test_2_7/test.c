#include<stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;
	ListNode *fast = head;
	ListNode *slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return NULL;
}