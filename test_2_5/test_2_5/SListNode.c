#include"SListNode.h"

// 动态申请一个节点
SListNode* BuySListNode(DataType x)
{
	SListNode *Node = (SListNode*)malloc(sizeof(SListNode));
	Node->val = x;
	Node->next = NULL;
}
// 单链表打印
void SListPrint(SListNode* p)
{
	
	SListNode *cur = p;
	while (cur)
	{
		printf("%d ->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** p, DataType x)
{
	
	SListNode *Node = BuySListNode(x);
	if (*p == NULL)
	{
		*p = Node;
	}
	else
	{
		SListNode *cur = *p;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = Node;
	}
}
// 单链表的头插 
void SListPushFront(SListNode** p, DataType x)
{
	
	SListNode *Node = BuySListNode(x);
	Node->next = *p;
	*p = Node;
}
// 单链表的尾删
void SListPopBack(SListNode** p)
{
	
	if (*p == NULL)
		return;
	else if ((*p)->next == NULL)
	{
		free(*p);
		*p = NULL;
	}
	else
	{
		SListNode *tail = *p;
		SListNode *prev = NULL;
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		prev->next = NULL;
	}

}
// 单链表头删 
void SListPopFront(SListNode** p)
{
	
	SListNode *cur = *p;
	*p = (*p)->next;
	free(cur);
	cur = NULL;
}
// 单链表查找 
SListNode* SListFind(SListNode* p, DataType x)
{
	
	SListNode *cur = p;
	while (cur)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x 
void SListInsertAfter(SListNode* pos, DataType x)
{
	
	SListNode *Node = BuySListNode(x);
	if (pos == NULL)
	{
		pos = Node;
		pos->next = NULL;
	}
	else
	{
		Node->next = pos->next;
		pos->next = Node;
	}
}
// 单链表删除pos位置之后的值
//void SListEraseAfter(SListNode* pos)
//{
//	if (pos == NULL)
//		return;
//	SListNode *next = pos->next;
//	pos->next = next->next;
//	free(next);
//	next = NULL;
//}
// 单链表销毁
void SListDestory(SListNode **p)
{

	SListNode *pre = NULL;
	SListNode *cur = *p;
	while (cur)
	{
		pre = cur;
		cur = cur->next;
		free(pre);
		pre = NULL;
	}
	*p = NULL;
}