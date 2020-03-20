#include<stdio.h>
#include<stdlib.h>

#pragma disable(warning:4996)

//�����ĸ�λ�ͻ�֮��
int subtractProductAndSum(int n){
	int pro = 1;
	int sum = 0;
	while (n)
	{
		int a = n % 10;
		sum = sum + a;
		pro = pro*a;
		n /= 10;
	}
	return pro - sum;
}
//ͳ��λ��Ϊż��������
int findNumbers(int* nums, int numsSize){
	int count = 0;

	for (int i = 0; i<numsSize; i++)
	{
		int sum = 0;
		while (nums[i])
		{
			nums[i] /= 10;
			sum++;
		}
		if (sum % 2 == 0)
		{
			count++;
		}
	}
	return count;
}

//ɾ���������ظ���Ԫ��
struct ListNode {
	int val;
	struct ListNode *next;
};
typedef struct ListNode ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head){

	if (head == NULL || head->next == NULL)
		return head;
	ListNode *cur = head;
	ListNode *pre = head;
	while (cur)
	{
		while (cur->next&&cur->val == cur->next->val)
		{
			cur = cur->next;
		}
		cur = cur->next;
		pre->next = cur;
		pre = pre->next;
	}
	return head;
}

//ɾ���������ظ�Ԫ�آ�
struct ListNode* deleteDuplicates(struct ListNode* head){
	if (head == NULL || head->next == NULL)
		return head;
	ListNode *HeadNode = (ListNode*)malloc(sizeof(ListNode));
	ListNode *cur = head;
	ListNode *pre = HeadNode;
	HeadNode->next = cur;
	while (cur)
	{
		if (cur->next&&cur->val == cur->next->val)
		{
			while (cur->next&&cur->val == cur->next->val)
			{
				cur = cur->next;
			}
			cur = cur->next;
			pre->next = cur;
		}
		else
		{
			pre->next = cur;
			cur = cur->next;
			pre = pre->next;
		}
	}
	return HeadNode->next;
}