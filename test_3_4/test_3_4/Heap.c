#include"Heap.h"


//向下调整算法

void AdjustDown(DataType *a, int root, int n)
{
	int parent = root;
	int child = parent * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n&&a[child] > a[child + 1])
			child++;
		if (a[parent]>a[child])
		{
			int temp = a[parent];
			a[parent] = a[child];
			a[child] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

// 堆的构建
void HeapCreate(Heap* hp, DataType* a, int n)
{
	hp->a = (DataType*)malloc(sizeof(DataType)*n);
	memcpy(hp->a, a, sizeof(DataType)*n);
	hp->size = n;
	hp->capacity = n;

	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, i, n);
	}
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	hp->size = hp->capacity = 0;
	hp->a = NULL;
}
// 堆的插入
void HeapPush(Heap* hp, DataType x)
{
	if (hp->size == hp->capacity)
	{
		DataType newcapacity = hp->capacity * 2;
		hp->a = (DataType*)realloc(hp->a, sizeof(DataType)*newcapacity);
		hp->capacity = newcapacity;
	}
	hp->a[hp->size++] = x;

	for (int i = (hp->size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, i, hp->size);
	}

}
// 堆的删除
void HeapPop(Heap* hp)
{
	int end = hp->a[0];
	hp->a[0] = hp->a[hp->size - 1];
	hp->a[hp->size - 1] = end;
	hp->size--;
	AdjustDown(hp->a, 0, hp->size);

}
// 取堆顶的数据
DataType HeapTop(Heap* hp)
{
	return hp->a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->size == 0 ? 1 : 0;
}
//堆的打印
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}