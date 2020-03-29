#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"


void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
//冒泡排序
void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
	}
}

//快速排序

//Hoare法
int HoareMethod(int *a, int begin, int end)
{
	int key = a[end];
	int keyindex = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		while (begin < end&&a[end] >= key)
			end--;
		swap(&a[begin], &a[end]);
	}
	swap(&a[begin], &a[keyindex]);
	return begin;
}
//挖坑法
int PitMethod(int *a, int begin, int end)
{
	int key = a[end];
	int pit = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
			begin++;
		a[pit] = a[begin];
		pit = begin;
		while (begin < end&&a[end] >= key)
			end--;
		a[pit] = a[end];
		pit = end;
	}
	pit = begin;
	a[pit] = key;
	return pit;
}

//前后指针法
int PrevcurMethod(int *a, int begin, int end)
{
	int key = a[end];
	int cur = begin;
	int pre = begin - 1;
	while (cur < end)
	{
		if (a[cur] < key&&++pre != cur)
			swap(&a[pre], &a[cur]);
		cur++;
	}
	pre++;
	swap(&a[pre], &a[cur]);
	return pre;
}

void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
		return;
	//int keyindex = HoareMethod(a, begin, end);
	//int keyindex = PitMethod(a, begin, end);
	int keyindex = PrevcurMethod(a, begin, end);
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);

}
//快速排序非递归
void QuickSortNor(int *a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);
		StackPop(&st);
		int keyindex = PrevcurMethod(a, left, right);
		if (left<keyindex - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyindex - 1);
		}
		if (right>keyindex + 1)
		{
			StackPush(&st, keyindex+1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}

//归并排序
void Merge(int *a, int left, int right,int *temp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	Merge(a, left, mid,temp);
	Merge(a, mid + 1, right,temp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1&&begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			temp[index++] = a[begin1++];
		else
			temp[index++] = a[begin2++];
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
			temp[index++] = a[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			temp[index++] = a[begin2++];
	}
	memcpy(a + left, temp + left, sizeof(int)*(right - left + 1));

}

void MergeSort(int* a, int n)
{
	int *temp = (int*)malloc(sizeof(int)*n);
	int left = 0;
	int right = n - 1;
	Merge(a, left, right, temp);
	free(temp);
}


void TestQuickSort(int *a, int begin, int end)
{
	//QuickSort(a, begin, end);
	QuickSortNor(a, begin, end);
	for (int i = 0; i <= end; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestMergeSort(int *a, int n)
{
	MergeSort(a, n);
	for (int i = 0; i <n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[10] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	TestQuickSort(a, 0, 9);
	//TestMergeSort(a, 10);
	system("pause");
	return 0;
}