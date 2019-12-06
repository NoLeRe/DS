#include"SeqList.h"


//≥ı ºªØÀ≥–Ú±Ì
void SeqListInit(pseq ps, size_t capacity)
{
	assert(ps);
	assert(capacity != 0);
	ps->capacity = capacity;
	ps->a = (SLDataType*)malloc(4 * sizeof(SLDataType));
	ps->size = 0;
}

//œ˙ªŸÀ≥–Ú±Ì
void SeqListDestory(pseq ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}

//¥Ú”°À≥–Ú±Ì
void SeqListPrint(pseq ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

//¿©»›
void CheckCapacity(pseq ps)
{   
	assert(ps);
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*ps->capacity);
	}

}

// À≥–Ú±ÌŒ≤≤Â 
void SeqListPushBack(pseq ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//À≥–Ú±ÌŒ≤…æ
void SeqListPopBack(pseq ps)
{
	assert(ps);
	ps->size--;
}

//À≥–Ú±ÌÕ∑≤Â
void SeqListPushFront(pseq ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}

// À≥–Ú±ÌÕ∑…æ 
void SeqListPopFront(pseq ps)
{
	assert(ps);

	for (size_t i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

//À≥–Ú±Ì≤È’“
int SeqListFind(pseq ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//À≥–Ú±Ì≤Â»Î
void SeqListInsert(pseq ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	CheckCapacity(ps);
	for (size_t i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;

}