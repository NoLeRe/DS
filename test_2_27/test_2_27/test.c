#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
int numComponents(struct ListNode* head, int* G, int GSize){

	ListNode *cur = head;
	int count = 0;
	int m = 0;
	while (cur)
	{
		int flag = 0;
		for (int i = 0; i<GSize; i++)
		{
			if (cur->val == G[i])
			{
				m++;
				flag++;
				break;
			}
		}
		if (m != 0 && flag == 0)
		{
			count++;
			m = 0;
		}
		if (cur->next == NULL&&flag != 0)
			count++;
		cur = cur->next;
	}
	return count;
}