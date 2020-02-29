#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int HpDataType;
typedef struct Heap{
	
	HpDataType *a;
	size_t size;
	size_t capacity;
}Heap;

// 堆的构建
void HeapCreate(Heap* hp, HpDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HpDataType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HpDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);