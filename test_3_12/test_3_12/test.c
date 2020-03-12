#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct {

	int *arr;
	int size;
	int capacity;


} KthLargest;

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
		if (child + 1<n&&a[child]>a[child + 1])
			child++;
		if (a[parent]>a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {

	KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
	obj->arr = (int*)malloc(sizeof(int)*k);
	obj->size = 0;
	obj->capacity = k;

	for (int i = 0; i<numsSize; i++)
	{
		kthLargestAdd(obj, nums[i]);
	}
	return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {


	if (obj->size == obj->capacity)
	{
		if (val <= obj->arr[0])
			return obj->arr[0];

		obj->arr[0] = val;
		AdjustDown(obj->arr, 0, obj->size);
		return obj->arr[0];
	}
	obj->arr[obj->size++] = val;
	if (obj->size - 2 >= 0)
	{
		for (int i = (obj->size - 2) / 2; i >= 0; i--)
			AdjustDown(obj->arr, i, obj->size);
	}
	return obj->arr[0];
}

void kthLargestFree(KthLargest* obj) {

	obj->size = 0;
	obj->arr = NULL;
}

/**
* Your KthLargest struct will be instantiated and called as such:
* KthLargest* obj = kthLargestCreate(k, nums, numsSize);
* int param_1 = kthLargestAdd(obj, val);

* kthLargestFree(obj);
*/

/**
* Your KthLargest struct will be instantiated and called as such:
* KthLargest* obj = kthLargestCreate(k, nums, numsSize);
* int param_1 = kthLargestAdd(obj, val);

* kthLargestFree(obj);
*/
int main()
{
	int *nums = NULL;
	KthLargest* obj = kthLargestCreate(1, nums, 0);
	int param_1 = kthLargestAdd(obj, -3);
	kthLargestFree(obj);
	return 0;
}