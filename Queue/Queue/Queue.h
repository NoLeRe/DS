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

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, DataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
DataType QueueFront(Queue* q);
// 获取队列队尾元素
DataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q); 
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
//打印队列
void QueuePrint(Queue* q);