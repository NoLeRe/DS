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

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}
// ��β�����
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
// ��ͷ������
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
// ��ȡ����ͷ��Ԫ��
DataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}
// ��ȡ���ж�βԪ��
DataType QueueBack(Queue* q)
{
	assert(q);
	return q->back->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	if (q->front == NULL)
		return 1;
	else
		return 0;

}
// ���ٶ���
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
	Queue q_1;
	Queue q_2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->q_1);
	QueueInit(&st->q_2);
	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&obj->q_1))
	{
		QueuePush(&obj->q_1, x);
	}
	else
		QueuePush(&obj->q_2, x);

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue *empty = &obj->q_1;
	Queue *noempty = &obj->q_2;
	if (!QueueEmpty(&obj->q_1))
	{
		noempty = &obj->q_1;
		empty = &obj->q_2;
	}
	while (QueueSize(noempty)>1)
	{
		QueuePush(empty, QueueFront(noempty));
		QueuePop(noempty);
	}
	int top = QueueFront(noempty);
	QueuePop(noempty);
	return top;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q_1))
		return QueueBack(&obj->q_1);
	else
		return QueueBack(&obj->q_2);

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {

	return QueueEmpty(&obj->q_1) && QueueEmpty(&obj->q_2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q_1);
	QueueDestroy(&obj->q_2);
	free(obj);
}

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/