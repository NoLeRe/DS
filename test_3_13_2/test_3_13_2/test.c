#include<stdio.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void AdjustDown(int *a, int root, int n)
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


int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){

	if ((arr == NULL) || (arrSize == 0) || (k == 0)) {
		*returnSize = 0;
		return NULL;
	}

	int *Heap = (int*)malloc(sizeof(int)*k);
	for (int i = 0; i<k; i++)
	{
		Heap[i] = arr[i];
	}
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(Heap, i, k);
	}
	for (int i = k; i<arrSize; i++)
	{
		if (arr[i]<Heap[0])
		{
			Heap[0] = arr[i];
			AdjustDown(Heap, 0, k);
		}
	}
	*returnSize = k;
	return Heap;


}