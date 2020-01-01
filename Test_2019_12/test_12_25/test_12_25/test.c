#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int val ;
	struct Node *next;
	struct Node *random;
}Node;

//复制带随机指针的链表
Node* copyRandomList(Node* head) {

	Node *cur = head;
	while (cur)
	{
		Node *next = cur->next;
		Node *copy = (Node*)malloc(sizeof(Node));
		copy->val = cur->val;
		copy->next = NULL;
		copy->random = NULL;
		cur->next = copy;
		copy->next = next;
		cur = next;
	}
	cur = head;
	while (cur)
	{
		Node *copy = cur->next;
		if (cur->random)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		cur = cur->next->next;

	}
	cur = head;
	Node *copyhead = NULL;
	Node *copytail = NULL;
	while (cur)
	{
		Node *copy = cur->next;
		Node *next = copy->next;
		if (copytail == NULL)
		{
			copyhead = copytail = copy;

		}
		else
		{
			copytail->next = copy;
			copytail = copy;

		}
		cur->next = next;
		cur = next;
	}
	return copyhead;
}

//对链表进行插入排序
struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->next = head;
	head = head->next;
	node->next->next = NULL;
	while (head)
	{
		ListNode *pre = node;
		ListNode *cur = node->next;
		ListNode *NextHead = head->next;
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
		head = NextHead;
	}
	return node->next;

}