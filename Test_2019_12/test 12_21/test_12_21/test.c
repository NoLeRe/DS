#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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

// 入栈
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

// 出栈
void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->top>0)
		ps->top--;
}
// 获取栈顶元素
DataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->data[ps->top - 1];
}
// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top == 0)
		return 1;
	return 0;
}
// 销毁栈
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

typedef struct {
	Stack st_1;
	Stack st_2;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->st_1);
	StackInit(&q->st_2);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {

	StackPush(&obj->st_1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->st_2))
	{
		while (!StackEmpty(&obj->st_1))
		{
			StackPush(&obj->st_2, StackTop(&obj->st_1));
			StackPop(&obj->st_1);
		}
	}
	int front = StackTop(&obj->st_2);
	StackPop(&obj->st_2);
	return front;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->st_2))
	{
		while (!StackEmpty(&obj->st_1))
		{
			StackPush(&obj->st_2, StackTop(&obj->st_1));
			StackPop(&obj->st_1);
		}
	}
	int front = StackTop(&obj->st_2);
	return front;

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {

	return StackEmpty(&obj->st_1) && StackEmpty(&obj->st_2);
}

void myQueueFree(MyQueue* obj) {

	StackDestroy(&obj->st_1);
	StackDestroy(&obj->st_2);
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/