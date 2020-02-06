#include"ListNode.h"

// 创建返回链表的头结点
ListNode* ListCreate()
{
	ListNode *Head_Node = (ListNode*)malloc(sizeof(ListNode));
	Head_Node->val = NULL;
	Head_Node->next = Head_Node;
	Head_Node->prev = Head_Node;
	return Head_Node;
}
//开辟空间
ListNode* BuyList(DataType x)
{
	ListNode *Node = (ListNode*)malloc(sizeof(ListNode));
	Node->val = x;
	Node->next = NULL;
	Node->prev = NULL;
	return Node;
}
// 双向链表销毁
void ListDestory(ListNode* p)
{
	ListNode *cur = p->next;
	while (cur != p)
	{
		free(cur);
		cur = cur->next;
	}
	free(p);
	p = NULL;
}
// 双向链表打印
void ListPrint(ListNode* p)
{
	if (p->next == p)
	{
		printf("NULL\n");
	}
	ListNode *cur = p->next;
	while (cur != p)
	{
		printf("%d ->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 双向链表尾插
void ListPushBack(ListNode* p, DataType x)
{
	ListNode *Node = BuyList(x);
	ListNode *prev = p->prev;
	prev->next = Node;
	Node->prev = prev;
	Node->next = p;
	p->prev = Node;
}
// 双向链表尾删
void ListPopBack(ListNode* p)
{
	ListNode *tail = p->prev;
	ListNode *prev = tail->prev;
	free(tail);
	tail = NULL;
	prev->next = p;
	p->prev = prev;
}
// 双向链表头插
void ListPushFront(ListNode* p, DataType x)
{
	ListNode *Node = BuyList(x);
	ListNode *next = p->next;
	p->next = Node;
	Node->next = next;
	next->prev = Node;
	Node->prev = p;
}
// 双向链表头删
void ListPopFront(ListNode* p)
{
	ListNode *Next = p->next;
	ListNode *Node = Next->next;
	free(Next);
	Next = NULL;
	p->next = Node;
	Node->prev = p;
}
// 双向链表查找
ListNode* ListFind(ListNode* p, DataType x)
{
	ListNode *cur = p->next;
	while (cur != p)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType x)
{
	ListNode *Node = BuyList(x);
	ListNode *prev = pos->prev;
	prev->next = Node;
	Node->next = pos;
	pos->prev = Node;
	Node->prev = prev;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode *next = pos->next;
	ListNode *prev = pos->prev;
	free(pos);
	pos = NULL;
	prev->next = next;
	next->prev = prev;
}