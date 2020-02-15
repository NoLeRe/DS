#include<stdio.h>
#include<stdlib.h>

void SListPopBack(ListNode *pplist)//βɾ
{
	if (pplist == NULL)
	{
		return;
	}
	else if (pplist->next == NULL)
	{
		free(pplist);
		pplist = NULL;
	}
	else
	{
		ListNode *tail = pplist;
		ListNode *prev = NULL;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		if (prev->next != NULL)
		{
			prev->next = NULL;
		}
	}
}