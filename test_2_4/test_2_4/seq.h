#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MaxSize 4
typedef int DataType;

typedef struct seq{

	DataType arr[MaxSize];
	int size;
	int capacity;
}seq;

//˳����ʼ��
void SeqListInit(seq *p);
// ˳������� 
void SeqListDestory(seq *p);
// ˳����ӡ 
void SeqListPrint(seq *p);
// ˳���β�� 
void SeqListPushBack(seq *p, DataType x);
// ˳���βɾ
void SeqListPopBack(seq *p);
// ˳���ͷ�� 
void SeqListPushFront(seq *p, DataType x);
// ˳���ͷɾ 
void SeqListPopFront(seq *p);
// ˳������
int SeqListFind(seq *p, DataType x);
//˳������
void SeqListInsert(seq *p, int pos, DataType x);