#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


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
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, DataType data)
{
	Node *node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = NULL;
	if (q->back == NULL)
	{
		q->front = q->back = node;
	}
	else
	{
		q->back->next = node;
		q->back = node;
	}

}
// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->back = NULL;
	}
	else
	{
		Node *next = q->front->next;
		free(q->front);
		q->front = next;
	}
}
// 获取队列头部元素
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// 获取队列队尾元素
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->back->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int count = 0;
	Node* cur = q->front;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;

}
// 销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	while (q->front)
	{
		Node* next = q->front->next;
		free(q->front);
		q->front = next;
	}
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q1);
	QueueInit(&st->q2);
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue *empty = &obj->q1;
	Queue *noempty = &obj->q2;
	if (!QueueEmpty(&obj->q1))
	{
		empty = &obj->q2;
		noempty = &obj->q1;
	}
	while (QueueSize(noempty)>1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	int top = QueueBack(noempty);
	QueuePop(noempty);

	return top;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {

	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);

}

void myStackFree(MyStack* obj) {

	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);

}

