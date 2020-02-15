#pragma once
#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

typedef int DataType;
typedef struct ListNode
{
	DataType data;
	struct ListNode *next;
}ListNode;

ListNode *BuyListNode(DataType x); //创建节点
void SListprint(ListNode *plist); //打印
void SListPushBack(ListNode **pplist, DataType x);//尾插
void SListPushFront(ListNode **pplist,DataType x);//头插
void SListPopBack(ListNode **pplist);//尾删
void SListPopFront(ListNode **pplist);//头删
ListNode* SListFind(ListNode* plist, DataType x);//单链表查找
void SListInsertAfter(ListNode* pos, DataType x);// 单链表在pos位置之后插入x
void SListEraseAfter(ListNode* pos);//删除pos位置之后的值
void SListDestory(ListNode *plist);//销毁链表