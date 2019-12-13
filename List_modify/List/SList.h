#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#pragma warning(disable:4996)

typedef int DataType;

typedef struct SListNode
{
	DataType data;
	struct SListNode *next;
	struct SListNode *prev;
}ListNode;

// 创建返回链表的头结点. 
ListNode* ListCreate(); 
// 双向链表销毁 
void ListDestory(ListNode* plist); 
// 双向链表打印
void ListPrint(ListNode* plist);
// 双向链表尾插
void ListPushBack(ListNode* plist, DataType x);
// 双向链表尾删
void ListPopBack(ListNode* plist);
// 双向链表头插
void ListPushFront(ListNode* plist, DataType x); 
// 双向链表头删
void ListPopFront(ListNode* plist); 
// 双向链表查找
ListNode* ListFind(ListNode* plist, DataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, DataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);
//开辟空间
ListNode* BuyList(DataType x);


