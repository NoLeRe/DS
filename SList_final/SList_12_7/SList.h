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

ListNode *BuyListNode(DataType x); //�����ڵ�
void SListprint(ListNode *plist); //��ӡ
void SListPushBack(ListNode **pplist, DataType x);//β��
void SListPushFront(ListNode **pplist,DataType x);//ͷ��
void SListPopBack(ListNode **pplist);//βɾ
void SListPopFront(ListNode **pplist);//ͷɾ
ListNode* SListFind(ListNode* plist, DataType x);//���������
void SListInsertAfter(ListNode* pos, DataType x);// ��������posλ��֮�����x
void SListEraseAfter(ListNode* pos);//ɾ��posλ��֮���ֵ
void SListDestory(ListNode *plist);//��������