#include"Stack.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->stack = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
// ��ջ 
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
// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps&&ps->top > 0);
	ps->top--;
}
// ��ȡջ��Ԫ�� 
DataType StackTop(Stack* ps)
{
	assert(ps&&ps->top > 0);
	return ps->stack[ps->top - 1];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط���(1)�������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->top > 0)
		return 0;
	else
		return 1;
}
// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->stack);
	ps->stack = NULL;
	ps->capacity = 0;
	ps->top = 0;
}