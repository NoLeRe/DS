#include "SList.h"

ListNode *BuyListNode(DataType x)	//�����ڵ�
{
	ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
	NewNode->data = x;
	NewNode->next = NULL;
}

void SListprint(ListNode *plist) //��ӡ
{
	
	while (plist)
	{
		printf("%d -> ", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

void SListPushBack(ListNode **pplist, DataType x)//β��
{
	ListNode *node = BuyListNode(x);
	if (*pplist == NULL)
	{
		*pplist = node;
	}
	else
	{
		ListNode *tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = node;
	}
}

void SListPushFront(ListNode **pplist, DataType x)//ͷ��
{
	ListNode *node = BuyListNode(x);
	node->next = *pplist;
	*pplist = node;
}

void SListPopBack(ListNode **pplist)//βɾ
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
		ListNode *tail = *pplist;
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
void SListPopFront(ListNode **pplist)//ͷɾ
{
	if (*pplist == NULL)
	{
		return;
	}
	else
	{
		ListNode *cur = *pplist;
		*pplist = (*pplist)->next;
		free(cur);
		cur = NULL;
	}
}

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
void SListInsertAfter(ListNode* pos, DataType x)//��Posλ�ú����
{
	
	ListNode *node=BuyListNode(x);
	if (pos == NULL)
	{
		pos = node;
		pos->next = NULL;
	}
	else
	{
		node->next = pos->next;
		pos->next = node;
	}
}
void SListEraseAfter(ListNode* pos) //ɾ��pos���ֵ
{
	if (pos == NULL)
	{
		return;
	}
	ListNode *next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}

void SListDestory(ListNode **pplist) //��������
{
	ListNode *cur = *pplist;
	ListNode *pre = NULL;
	while (cur)
	{
		pre = cur;
		cur = cur->next;
		free(pre);
		pre = NULL;
	}
	*pplist = NULL;
}