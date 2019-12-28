#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_a = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->_top == ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = data;
	ps->_top++;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	--ps->_top;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط���(1)�������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 1 : 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->_a);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}
bool isValid(char * s){

	Stack st;
	StackInit(&st);
	char *symbol[] = { "{}", "[]", "()" };
	while (*s)
	{
		if (*s == '{' || *s == '[' || *s == '(')
		{
			StackPush(&st, *s);
		}
		else
		{
			if (StackEmpty(&st) != 0)
				return false;
			char top = StackTop(&st);
			StackPop(&st);
			for (int i = 0; i<3; i++)
			{
				if (*s == symbol[i][1] && top != symbol[i][0])
					return false;
			}
		}
		s++;
	}
	bool ret = StackEmpty(&st);
	StackDestroy(&st);
	return ret;
}