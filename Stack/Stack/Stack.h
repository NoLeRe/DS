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
//��ӡջ
void StackPrint(Stack* ps);

