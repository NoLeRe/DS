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

// �������������ͷ���. 
ListNode* ListCreate(); 
// ˫���������� 
void ListDestory(ListNode* plist); 
// ˫�������ӡ
void ListPrint(ListNode* plist);
// ˫������β��
void ListPushBack(ListNode* plist, DataType x);
// ˫������βɾ
void ListPopBack(ListNode* plist);
// ˫������ͷ��
void ListPushFront(ListNode* plist, DataType x); 
// ˫������ͷɾ
void ListPopFront(ListNode* plist); 
// ˫���������
ListNode* ListFind(ListNode* plist, DataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, DataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
//���ٿռ�
ListNode* BuyList(DataType x);


