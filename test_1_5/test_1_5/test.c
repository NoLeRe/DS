#include<stdio.h>
#include<stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode ListNode;
bool isPalindrome(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return true;

	ListNode *fast = head;
	ListNode *slow = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *pre = NULL;
	ListNode *next = NULL;
	while (next != slow)
	{
		next = head->next;
		head->next = pre;
		pre = head;
		head = next;
	}
	if (fast&&fast->next == NULL)
	{
		slow = slow->next;
	}
	while (slow)
	{
		if (slow->val != pre->val)
			return false;
		slow = slow->next;
		pre = pre->next;
	}
	return true;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

	ListNode *stand = headA;
	while (headB)
	{
		while (stand)
		{
			if (stand == headB)
				return stand;
			stand = stand->next;
		}
		stand = headA;
		headB = headB->next;
	}
	return NULL;
}