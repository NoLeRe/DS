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

//顺序表初始化
void SeqListInit(pseq ps, size_t capacity);
// 顺序表销毁 
void SeqListDestory(pseq ps);
// 顺序表打印 
void SeqListPrint(pseq ps);
// 检查空间，如果满了，进行增容 
void CheckCapacity(pseq ps);
// 顺序表尾插 
void SeqListPushBack(pseq ps, SLDataType x);
// 顺序表尾删
void SeqListPopBack(pseq ps);
// 顺序表头插 
void SeqListPushFront(pseq ps, SLDataType x);
// 顺序表头删 
void SeqListPopFront(pseq ps);
// 顺序表查找
int SeqListFind(pseq ps, SLDataType x);
//顺序表插入
void SeqListInsert(pseq ps, int pos, SLDataType x);