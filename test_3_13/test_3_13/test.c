#include<stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Adjustdown(int *a, int root, int n)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1<n&&a[child]<a[child + 1])
			child++;
		if (a[parent]<a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

int lastStoneWeight(int* stones, int stonesSize){
	if (stonesSize<2)
		return stones[0];
	int size = stonesSize;
	int Heap[size];
	for (int i = 0; i<stonesSize; i++)
	{
		Heap[i] = stones[i];
	}

	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		Adjustdown(Heap, i, size);
	}

	int stone1, stone2;
	while (size>1)
	{
		stone1 = Heap[0];
		swap(&Heap[0], &Heap[size - 1]);
		size--;
		Adjustdown(Heap, 0, size);

		stone2 = Heap[0];
		swap(&Heap[0], &Heap[size - 1]);
		size--;
		Adjustdown(Heap, 0, size);

		if (stone1 != stone2)
		{
			int sum = abs(stone1 - stone2);
			Heap[size++] = sum;


			for (int i = (size - 2) / 2; i >= 0; i--)
			{
				Adjustdown(Heap, i, size);
			}
		}
	}
	if (size == 0)
		return 0;
	return Heap[0];
}