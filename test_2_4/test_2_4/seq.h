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

//顺序表初始化
void SeqListInit(seq *p);
// 顺序表销毁 
void SeqListDestory(seq *p);
// 顺序表打印 
void SeqListPrint(seq *p);
// 顺序表尾插 
void SeqListPushBack(seq *p, DataType x);
// 顺序表尾删
void SeqListPopBack(seq *p);
// 顺序表头插 
void SeqListPushFront(seq *p, DataType x);
// 顺序表头删 
void SeqListPopFront(seq *p);
// 顺序表查找
int SeqListFind(seq *p, DataType x);
//顺序表插入
void SeqListInsert(seq *p, int pos, DataType x);