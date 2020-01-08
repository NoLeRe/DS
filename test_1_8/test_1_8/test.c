#include<stdio.h>
#include<stdlib.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* reverseList(struct ListNode* head){

	ListNode *cur = head;
	ListNode *pre = NULL;

	while (cur)
	{
		ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
		Node->val = cur->val;
		Node->next = pre;
		pre = Node;
		cur = cur->next;
	}
	return pre;
}
struct ListNode* deleteNode(struct ListNode* head, int val){

	ListNode *cur = head;
	ListNode *pre = NULL;
	while (cur)
	{
		ListNode *next = cur->next;
		if (cur->val == val)
		{
			if (cur->next != NULL)
			{
				cur->val = next->val;
				cur->next = next->next;
			}
			else
			{
				pre->next = cur->next;
			}
		}
		pre = cur;
		cur = cur->next;
	}
	return head;

}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

	ListNode *fast = headA;
	ListNode *slow = headB;
	while (slow)
	{
		while (fast)
		{
			if (slow == fast)
				return fast;
			fast = fast->next;
		}
		fast = headA;
		slow = slow->next;
	}
	return NULL;
}