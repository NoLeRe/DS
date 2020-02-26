#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){

	ListNode *cur = root;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	cur = root;

	ListNode **arr = (ListNode**)calloc(k, sizeof(ListNode*));
	ListNode *pre = root;
	int size = count / k;
	int len = count%k;
	for (int i = 0; i<k; i++)
	{
		arr[i] = cur;
		if (i<len)
		{
			int j = 0;
			while (j<size)
			{
				j++;
				cur = cur->next;
			}
			pre = cur;
			cur = cur->next;
			pre->next = NULL;
		}
		else
		{
			if (size != 0)
			{
				int j = 1;
				while (j<size)
				{
					j++;
					cur = cur->next;
				}
				pre = cur;
				cur = cur->next;
				pre->next = NULL;
			}
			else
			{
				arr[i] = NULL;
			}
		}
	}
	*returnSize = k;
	return arr;
}

