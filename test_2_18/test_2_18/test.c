#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
}ListNode;

ListNode* SListFind(ListNode* plist, DataType x)
{
	if (plist == NULL)
	{
		return;
	}
	while (plist)
	{
		if (plist->data == x)
		{
			return plist;
		}
		else
		{
			plist = plist->next;
		}
	}
	return NULL;
}