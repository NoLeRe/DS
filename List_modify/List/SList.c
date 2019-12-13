#include"SList.h"

// 创建返回链表的头结点. 
ListNode* ListCreate()  
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->data = NULL;
	head->next = head;
	head->prev = head;

	return head;
}

// 开辟空间
ListNode* BuyList(DataType x) 
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// 双向链表销毁 
void ListDestory(ListNode* plist) 
{
	ListNode *cur = plist->next;
	while (cur != plist)
	{
		free(cur);
		cur = cur->next;
	}
	free(plist);
	plist = NULL;
}

// 双向链表打印
void ListPrint(ListNode* plist) 
{
	if (plist->next == plist)
	{
		printf("NULL\n");
	}
	ListNode *cur = plist->next;
	while (cur != plist)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* plist, DataType x)
{
	ListNode *node = BuyList(x);
	ListNode *prev = plist->prev;
	prev->next = node;
	node->next = plist;
	node->prev = prev;
	plist->prev = node;
}

// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	ListNode *tail = plist->prev;
	ListNode *prev = tail->prev;
	free(tail);
	tail = NULL;
	plist->prev = prev;
	prev->next = plist;
}

// 双向链表头插
void ListPushFront(ListNode* plist, DataType x)
{
	ListNode *node = BuyList(x);
	ListNode *first = plist->next;
	plist->next = node;
	node->next = first;
	first->prev = node;
	node->prev = plist;
}

// 双向链表头删
void ListPopFront(ListNode* plist)
{
	assert(plist&&plist->next != plist);

	ListNode *first = plist->next;
	ListNode *second = plist->next->next;
	free(first);
	first = NULL;
	plist->next = second;
	second->prev = plist;

}

// 双向链表查找
ListNode* ListFind(ListNode* plist, DataType x)
{
	ListNode *cur = plist->next;
	while (cur->next != plist)
	{
		if (cur->data == x)
			return cur;
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType x)
{
	ListNode *node = BuyList(x);
	ListNode *prev = pos->prev;
	prev->next = node;
	node->next = pos;
	node->prev = prev;
	pos->prev = node;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode *prev = pos->prev;
	ListNode *next = pos->next;
	free(pos);
	pos = NULL;
	prev->next = next;
	next->prev = prev;
}