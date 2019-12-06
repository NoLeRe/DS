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


void SListprint(SList *plist);  //¥Ú”°¡¥±Ì
void SListPushBack(SList **pplist, DataType x);//Œ≤≤Â
void SListPushFront(SList **pplist, DataType x);//Õ∑≤Â
void SListPopBack(SList **pplist); //Œ≤…æ
void SListPopFront(SList **pplist); //Õ∑…æ