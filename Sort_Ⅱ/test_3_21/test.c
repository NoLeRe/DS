#include<stdio.h>


void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if (a[j]>a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int  HoareMethod(int *a, int beain, int end)
{
	int key = a[end];
	int keyindex = end;
	while (beain < end)
	{
		while (beain < end&&a[beain] <= key)
			beain++;
		while (beain < end&&a[end] >= key)
			end--;
		swap(&a[beain], &a[end]);
	}
	swap(&a[beain], &a[keyindex]);
	return beain;
}

int  PitMethod(int *a, int begin,int end)
{
	int key = a[end];
	int pit = end;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
		{
			begin++;
		}
		a[pit] = a[begin];
		pit = begin;
		while (begin < end&&a[end] >= key)
		{
			end--;
		}
		a[pit] = a[end];
		pit = end;
	}
	a[pit] = key;
	return pit;
}

int PrevCurMethod(int* a, int begin, int end)
{
	int pre = begin - 1;
	int cur = begin;
	while (cur < end)
	{
		if (a[cur] < a[end] && ++pre != cur)
			swap(&a[cur], &a[pre]);
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
	int keyindex = PrevCurMethod(a, begin, end);
	QuickSort(a, begin, keyindex - 1);
	QuickSort(a, keyindex + 1, end);
	
}
void TestQuickSort(int *a, int begin,int end)
{
	QuickSort(a, begin, end);
	for (int i = 0; i <= end; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int a[10] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	TestQuickSort(a, 0, 9);
	system("pause");
	return 0;
}