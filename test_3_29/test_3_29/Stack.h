#pragma once
#pragma warning(disable:4996)
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

// 初始化栈 
void StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, DataType data);
// 出栈
void StackPop(Stack* ps);
// 获取栈顶元素
DataType StackTop(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps);



// 初始化栈 
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
		return NULL;
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}