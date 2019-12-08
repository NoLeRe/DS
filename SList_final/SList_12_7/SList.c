#include "SList.h"

ListNode *BuyListNode(DataType x)	//创建节点
{
	ListNode *NewNode = (ListNode *)malloc(sizeof(ListNode));
	NewNode->data = x;
	NewNode->next = NULL;
}

void SListprint(ListNode *plist) //打印
{
	
	while (plist)
	{
		printf("%d -> ", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

void SListPushBack(ListNode **pplist, DataType x)//尾插
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

void SListPushFront(ListNode **pplist, DataType x)//头插
{
	ListNode *node = BuyListNode(x);
	node->next = *pplist;
	*pplist = node;
}

void SListPopBack(ListNode **pplist)//尾删
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
void SListPopFront(ListNode **pplist)//头删
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
void SListInsertAfter(ListNode* pos, DataType x)//在Pos位置后插入
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
void SListEraseAfter(ListNode* pos) //删除pos后的值
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

void SListDestory(ListNode **pplist) //销毁链表
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