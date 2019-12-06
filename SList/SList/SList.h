#pragma once

#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

typedef int DataType;

typedef struct SList
{
	DataType data;
	struct SList *next;
}SList;


void SListprint(SList *plist);  //��ӡ����
void SListPushBack(SList **pplist, DataType x);//β��
void SListPushFront(SList **pplist, DataType x);//ͷ��
void SListPopBack(SList **pplist); //βɾ
void SListPopFront(SList **pplist); //ͷɾ