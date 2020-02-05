#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
typedef int DataType;
typedef struct SListNode{
	DataType val;
	struct SListNode *next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(DataType x);
// �������ӡ
void SListPrint(SListNode* p);
// ������β��
void SListPushBack(SListNode** p, DataType x);
// �������ͷ�� 
void SListPushFront(SListNode** p, DataType x);
// �������βɾ
void SListPopBack(SListNode** p);
// ������ͷɾ 
void SListPopFront(SListNode** p);
// ��������� 
SListNode* SListFind(SListNode* p, DataType x); 
// ��������posλ��֮�����x  
void SListInsertAfter(SListNode* pos, DataType x); 
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);
// ����������
void SListDestory(SListNode **p);