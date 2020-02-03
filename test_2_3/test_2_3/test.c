#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)


struct ListNode{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;

struct ListNode* removeElements(struct ListNode* head, int val) //移除链表元素
{

	ListNode *pre = NULL;
	ListNode *Next = head;
	while (Next)
	{
		if (Next->val == val)
		{
			ListNode *temp = Next->next;
			free(Next);
			if (Next == head)
				head = temp;
			else
				pre->next = temp;
			Next = temp;
		}
		else
		{
			pre = Next;
			Next = Next->next;
		}
	}
	return head;
}
struct ListNode* reverseList(struct ListNode* head) //反转链表
{

	ListNode *pre = NULL;
	ListNode *cur = head;
	while (head)
	{
		head = head->next;
		cur->next = pre;
		pre = cur;
		cur = head;
	}
	return pre;
}

struct ListNode* middleNode(struct ListNode* head) //链表的中间结点
{

	ListNode *slow = head;
	ListNode *fast = head;
	while (fast&&fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) //从倒数第K个节点返回
{
	ListNode *slow = pListHead;
	ListNode *fast = pListHead;
	if (pListHead == NULL)
		return NULL;
	while (k&&fast)
	{
		fast = fast->next;
		k--;
	}
	if (k>0 && fast == NULL)
		return NULL;
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) //合并两个有序链表
{

	ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
	ListNode *cur = Node;
	while (l1&&l2)
	{
		if (l1->val<l2->val)
		{
			Node->next = l1;
			l1 = l1->next;
		}
		else
		{
			Node->next = l2;
			l2 = l2->next;
		}
		Node = Node->next;
	}
	if (l1 != NULL)
	{
		Node->next = l1;
	}
	else if (l2 != NULL)
	{
		Node->next = l2;
	}
	else
		return NULL;
	return cur->next;
}