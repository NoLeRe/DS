#include"seq.h"

//顺序表初始化
void SeqListInit(seq *p)
{
	assert(p);
	for (p->size = 0; p->size < MaxSize; p->size++)
		p->arr[p->size] = 0;
	p->size = 0;
}
// 顺序表销毁 
void SeqListDestory(seq *p)
{
	assert(p);
	p->size = 0;
}
// 顺序表打印 
void SeqListPrint(seq *p)
{
	assert(p);
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
}
// 顺序表尾插 
void SeqListPushBack(seq *p, DataType x)
{
	assert(p);
	if (p->size >= MaxSize)
	{
		printf("顺序表已满！\n");
		return;
	}
	p->arr[p->size] = x;
	p->size++;
}
// 顺序表尾删
void SeqListPopBack(seq *p)
{
	assert(p);
	p->size--;
}
// 顺序表头插 
void SeqListPushFront(seq *p, DataType x)
{
	assert(p);
	if (p->size >= MaxSize)
	{
		printf("顺序表已满！\n");
		return;
	}
	p->arr[p->size] = x;
	for (int i = p->size; i >0; i--)
	{
		int temp = p->arr[i];
		p->arr[i] = p->arr[i - 1];
		p->arr[i - 1] = temp;
	}
	p->size++;
}
// 顺序表头删 
void SeqListPopFront(seq *p)
{
	assert(p);
	for (int i = 0; i <p->size-1; i++)
	{
		int temp = p->arr[i];
		p->arr[i] = p->arr[i + 1];
		p->arr[i + 1] = temp;
	}
	p->size--;
}
// 顺序表查找
int SeqListFind(seq *p, DataType x)
{
	assert(p);
	for (int i = 0; i < p->size - 1; i++)
	{
		if (p->arr[i] == x)
			return i+1;
	}
	return -1;
}
//顺序表插入
void SeqListInsert(seq *p, int pos, DataType x)
{
	assert(p);
	if (p->size >= MaxSize)
	{
		printf("顺序表已满！\n");
		return;
	}
	p->arr[p->size++] = x;
	for (int i = p->size-1; i >pos-1; i--)
	{
		int temp = p->arr[i];
		p->arr[i] = p->arr[i - 1];
		p->arr[i - 1] = temp;
	}
}


