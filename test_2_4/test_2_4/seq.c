#include"seq.h"

//˳����ʼ��
void SeqListInit(seq *p)
{
	assert(p);
	for (p->size = 0; p->size < MaxSize; p->size++)
		p->arr[p->size] = 0;
	p->size = 0;
}
// ˳������� 
void SeqListDestory(seq *p)
{
	assert(p);
	p->size = 0;
}
// ˳����ӡ 
void SeqListPrint(seq *p)
{
	assert(p);
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->arr[i]);
	}
	printf("\n");
}
// ˳���β�� 
void SeqListPushBack(seq *p, DataType x)
{
	assert(p);
	if (p->size >= MaxSize)
	{
		printf("˳���������\n");
		return;
	}
	p->arr[p->size] = x;
	p->size++;
}
// ˳���βɾ
void SeqListPopBack(seq *p)
{
	assert(p);
	p->size--;
}
// ˳���ͷ�� 
void SeqListPushFront(seq *p, DataType x)
{
	assert(p);
	if (p->size >= MaxSize)
	{
		printf("˳���������\n");
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
// ˳���ͷɾ 
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
// ˳������
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
//˳������
void SeqListInsert(seq *p, int pos, DataType x)
{
	assert(p);
	if (p->size >= MaxSize)
	{
		printf("˳���������\n");
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


