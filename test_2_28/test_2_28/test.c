#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
int* nextLargerNodes(struct ListNode* head, int* returnSize){

	ListNode *cur = head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	int *arr = (int*)malloc(sizeof(int)*count);
	*returnSize = count;

	cur = head;
	int i = 0;
	while (cur)
	{
		ListNode *next = cur->next;
		while (next)
		{
			if (cur->val<next->val)
			{
				cur->val = next->val;
				break;
			}
			next = next->next;
		}
		if (next == NULL)
		{
			cur->val = 0;
		}
		arr[i++] = cur->val;
		cur = cur->next;
	}
	return arr;
}