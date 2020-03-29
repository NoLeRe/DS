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

// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ
void StackPush(Stack* ps, DataType data);
// ��ջ
void StackPop(Stack* ps);
// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps);
// ����ջ
void StackDestroy(Stack* ps);



// ��ʼ��ջ 
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
		return NULL;
	free(ps->data);
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}