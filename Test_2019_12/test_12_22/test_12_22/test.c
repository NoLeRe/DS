#include<stdio.h>
#include<stdlib.h>

#pragma warning(disable:4996)

typedef int DataType;
typedef struct Stack
{
	DataType *data;
	int top;
	int capacity;
}Stack;
void StackInit(Stack* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

// ��ջ
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		size_t newcapacity = (ps->capacity == 0 ? 4 : (ps->capacity) * 2);
		ps->data = (DataType*)realloc(ps->data, sizeof(DataType)*newcapacity);
		ps->capacity = newcapacity;

	}
	ps->data[ps->top++] = data;
}

// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top>0)
		ps->top--;
}
// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->data[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
		return 1;
	return 0;
}
// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->data == NULL)
		return;
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

//ջʵ�ֶ���
typedef struct {
	int data;
	Stack s1;
	Stack s2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->s1);
	StackInit(&q->s2);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {

	StackPush(&obj->s1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {

	if (StackEmpty(&obj->s2))
	{
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}

	int Top = StackTop(&obj->s2);
	StackPop(&obj->s2);
	return Top;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->s2))
	{
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}

	int front = StackTop(&obj->s2);

	return front;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {

	return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);

}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);

	free(obj);
}

//�ཻ����
 struct ListNode {
     int val;
     struct ListNode *next;
 };

typedef struct ListNode ListNode;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {


	while (headB)
	{
		ListNode *fast = headA;
		while (fast)
		{
			if (fast == headB)
				return headB;
			fast = fast->next;
		}
		headB = headB->next;
	}
	return NULL;

}