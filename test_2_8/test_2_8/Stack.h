#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct Stack{
	DataType *stack;
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
// 检测栈是否为空，如果为空返回非零(1)，如果不为空返回0 
int StackEmpty(Stack* ps);
// 销毁栈 
void StackDestroy(Stack* ps);

