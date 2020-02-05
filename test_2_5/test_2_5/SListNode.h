#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef int DataType;
typedef struct SListNode{
	DataType val;
	struct SListNode *next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(DataType x);
// 单链表打印
void SListPrint(SListNode* p);
// 单链表尾插
void SListPushBack(SListNode** p, DataType x);
// 单链表的头插 
void SListPushFront(SListNode** p, DataType x);
// 单链表的尾删
void SListPopBack(SListNode** p);
// 单链表头删 
void SListPopFront(SListNode** p);
// 单链表查找 
SListNode* SListFind(SListNode* p, DataType x); 
// 单链表在pos位置之后插入x  
void SListInsertAfter(SListNode* pos, DataType x); 
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos);
// 单链表销毁
void SListDestory(SListNode **p);