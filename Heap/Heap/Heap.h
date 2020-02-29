#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int HpDataType;
typedef struct Heap{
	
	HpDataType *a;
	size_t size;
	size_t capacity;
}Heap;

// �ѵĹ���
void HeapCreate(Heap* hp, HpDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HpDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HpDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);