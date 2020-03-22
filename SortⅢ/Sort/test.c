#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


//快速排序
int GetMid(int *a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] > a[mid])
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[mid]>a[begin])
			return mid;
		else if (a[begin] > a[end])
			return end;
		else
			return begin;
	}
}

int  HoareMethod(int *a, int begin, int end)  //Hoare法
{
	swap(&a[end], &a[GetMid(a, begin, end)]);
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

int PitMethod(int *a, int begin, int end)   //挖坑法
{
	swap(&a[end], &a[GetMid(a, begin, end)]);
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
	a[pit] = key;
	return pit;
}

int PrevCurMethod(int* a, int begin, int end)  //前后指针法
{
	swap(&a[end], &a[GetMid(a, begin, end)]);
	int cur = begin;
	int pre = begin - 1;
	while (cur < end)
	{
		if (a[cur] < a[end] && ++pre != cur)
			swap(&a[pre], &a[cur]);
		cur++;
	}
	pre++;
	swap(&a[pre], &a[end]);
	return pre;
}

void QucikSortNor(int *a, int begin, int end)   //非递归快速排序
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
		int keyindex = PrevCurMethod(a, left, right);
		if (left < keyindex - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyindex - 1);
		}
		if (right>keyindex + 1)
		{
			StackPush(&st, keyindex + 1);
			StackPush(&st, right);
		}
	}
	StackDestroy(&st);
}


void QuickSort(int *a, int begin, int end)
{
	if (begin >= end)
		return;
	//int keyindex = HoareMethod(a, begin, end);
	//int keyindex = PitMethod(a, begin, end);
	int keyindex = PrevCurMethod(a, begin, end);

	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);

}

//归并排序
void _mergeSort(int *a, int begin, int end, int *temp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_mergeSort(a, begin, mid, temp);
	_mergeSort(a, mid + 1, end, temp);
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int index = begin;
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
	memcpy(a+begin, temp+begin, sizeof(int)*(end - begin + 1));

}
void MergeSort(int *a, int n)
{
	int *temp = (int*)malloc(sizeof(int)*n);
	_mergeSort(a, 0, n - 1, temp);
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


void TestQuickSort(int *a, int begin, int end)
{
	//QuickSort(a, begin, end);
	QucikSortNor(a, begin, end);
	for (int i = 0; i <= end; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[10] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	//TestQuickSort(a, 0, 9);
	TestMergeSort(a, 10);
	system("pause");
	return 0;
}