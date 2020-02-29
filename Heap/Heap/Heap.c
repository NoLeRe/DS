#include"Heap.h"


//向下调整算法
void AdjustDown(HpDataType *a,int n, HpDataType root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child] > a[child + 1])
			child++;
		if (a[parent]>a[child])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
//向上调整算法
void AdjustUp(Heap *hp, HpDataType child)
{
	int parent = (child - 1) / 2;

	while (child)
	{
		if (hp->a[child] < hp->a[parent])
		{
			int tmp = hp->a[parent];
			hp->a[parent] = hp->a[child];
			hp->a[child] = tmp;
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}		
	

// 堆的构建
void HeapCreate(Heap* hp, HpDataType* a, int n)
{
	hp->a = (HpDataType*)malloc(sizeof(HpDataType)*n);
	memcpy(hp->a, a, sizeof(HpDataType)*n);
	hp->size = n;
	hp->capacity = n;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a,hp->size, i);
	}
	
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	hp->size = 0;
	hp->capacity = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HpDataType x)
{
	if (hp->size == hp->capacity)
	{
		HpDataType newcapacity = hp->capacity * 2;
		hp->a = (HpDataType*)realloc(hp->a, sizeof(HpDataType)*newcapacity);
		hp->capacity = newcapacity;
	}
	hp->a[hp->size++] = x;

	for (int i = (hp->size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->a, hp->size, i);
	}

}
// 堆的删除
void HeapPop(Heap* hp)
{
	
	int temp = hp->a[0];
	hp->a[0] = hp->a[hp->size - 1];
	hp->a[hp->size - 1] = temp;

	hp->size--;

	AdjustDown(hp->a, hp->size, 0);
}
// 取堆顶的数据
HpDataType HeapTop(Heap* hp)
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
int HeapPrint(Heap *hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}