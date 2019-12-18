#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#pragma warning(disable:4996)

typedef int DataType;

typedef struct QueueNode
{
	DataType data;
	struct QueueNode *next;
}Node;

typedef struct Queue
{
	Node *front;
	Node *back;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, DataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
DataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q); 
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
//��ӡ����
void QueuePrint(Queue* q);