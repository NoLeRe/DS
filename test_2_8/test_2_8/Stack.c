#include"Stack.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->stack = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
// 入栈 
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->stack = (DataType*)realloc(ps->stack, sizeof(DataType)*newcapacity);
		ps->capacity = newcapacity;
	}
	ps->stack[ps->top++] = data;
}
// 出栈 
void StackPop(Stack* ps)
{
	assert(ps&&ps->top > 0);
	ps->top--;
}
// 获取栈顶元素 
DataType StackTop(Stack* ps)
{
	assert(ps&&ps->top > 0);
	return ps->stack[ps->top - 1];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// 检测栈是否为空，如果为空返回非零(1)，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top > 0)
		return 0;
	else
		return 1;
}
// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->stack);
	ps->stack = NULL;
	ps->capacity = 0;
	ps->top = 0;
}