#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *a;
	size_t size;
	size_t capacity;
}Seq,*pseq;

//˳����ʼ��
void SeqListInit(pseq ps, size_t capacity);
// ˳������� 
void SeqListDestory(pseq ps);
// ˳����ӡ 
void SeqListPrint(pseq ps);
// ���ռ䣬������ˣ��������� 
void CheckCapacity(pseq ps);
// ˳���β�� 
void SeqListPushBack(pseq ps, SLDataType x);
// ˳���βɾ
void SeqListPopBack(pseq ps);
// ˳���ͷ�� 
void SeqListPushFront(pseq ps, SLDataType x);
// ˳���ͷɾ 
void SeqListPopFront(pseq ps);
// ˳������
int SeqListFind(pseq ps, SLDataType x);
//˳������
void SeqListInsert(pseq ps, int pos, SLDataType x);