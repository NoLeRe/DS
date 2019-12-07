#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)



struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;                     
struct ListNode* middleNode(struct ListNode* head) //������м�ڵ�
{													
	ListNode *slow = head;
	ListNode *fast = head;
	while (fast != NULL&&fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

struct ListNode* reverseList(struct ListNode* head)   //��ת����
{
	ListNode *cur = head;
	ListNode *pre = NULL;
	while (cur != NULL)
	{
		head = head->next;
		cur->next = pre;
		pre = cur;
		cur = head;
	}
	return pre;

}

struct ListNode* removeElements(struct ListNode* head, int val)  //�Ƴ�����Ԫ��
{
	ListNode *plist = head;
	ListNode *cur = NULL;
	while (plist != NULL)
	{
		if (plist->val == val)
		{
			ListNode *temp = plist->next;
			free(plist);
			if (plist == head)
			{
				head = temp;
			}
			else
			{
				cur->next = temp;
			}
			plist = temp;
		}
		else
		{
			cur = plist;
			plist = plist->next;
		}
	}
	return head;

}