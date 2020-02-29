#include<stdio.h>

void AdjustDown(int *a,int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
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

void HeapSort(int* a, int n)
{
	for (int i = n-1; i >=0; i--)
	{
		int temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		AdjustDown(a, i, 0);
	}
}

void PrintTopK(int* a, int n, int k)
{
	HeapSort(a, n);
	printf("Ç°%dÃû£º ",k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void TestTopk()
{
	int a[10] = { 15, 18, 19, 28, 27, 31, 25, 49, 34, 65 };
	PrintTopK(a, 10, 3);
}

int main()
{
	int a[10] = { 15, 18, 19, 28, 27, 31, 25, 49, 34, 65 };
	/*HeapSort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");*/
	PrintTopK(a, 10, 3);
	system("pause");
	return 0;
}

