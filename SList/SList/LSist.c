#include "SList.h"

void SListprint(SList *plist)   //´òÓ¡Á´±í
{
	SList *cur = plist;
	while(cur!= NULL)
	{
		printf("%d ->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

SList *BuySListNode(DataType x)  //¿ª±Ù¿Õ¼ä
{
	SList *NewNode = (SList*)malloc(sizeof(SList));
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

void SListPushBack(SList **pplist, DataType x) //Î²²å
{
	SList *NewNode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = NewNode;
	}
	else
	{
		SList *tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = NewNode;
	}
}
void SListPushFront(SList **pplist, DataType x) //Í·²å
{
	SList *NewNode = BuySListNode(x);
	NewNode->next = *pplist;
	*pplist = NewNode;
}

void SListPopBack(SList **pplist)  //Î²É¾
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{	
		SList *prev = NULL;
		SList *tail = *pplist;
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
void SListPopFront(SList **pplist)  //Í·É¾
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist= NULL;
	}
	else
	{
		SList *cur = *pplist;
		*pplist = (*pplist)->next;
		free(cur);
		cur = NULL;
	}
}