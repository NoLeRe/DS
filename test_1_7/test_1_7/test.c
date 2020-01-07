#include<stdio.h>
#include<stdlib.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
void deleteNode(struct ListNode* node) {


	node->val = node->next->val;
	node->next = node->next->next;

}
struct ListNode* getKthFromEnd(struct ListNode* head, int k){

	ListNode *slow = head;
	ListNode *fast = head;
	while (k--)
	{
		fast = fast->next;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;

}